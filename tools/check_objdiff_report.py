#!/usr/bin/env python3
"""Validate report coverage and reject misleading progress percentages."""

from __future__ import annotations

import json
import sys
from pathlib import Path


EXPECTED_ROM_SIZE = 0x1000000
EXPECTED_CODE = 257896
EXPECTED_DATA = 16519320
EXPECTED_FUNCTIONS = 1354
EXPECTED_UNITS = 1908


def fail(message: str) -> None:
    raise SystemExit(f"invalid objdiff report: {message}")


def validate_complete_units(report: dict[str, object]) -> None:
    for unit in report["units"]:
        if not unit.get("metadata", {}).get("complete", False):
            continue
        measures = unit["measures"]
        for total_key, percent_key in (
            ("total_code", "matched_code_percent"),
            ("total_data", "matched_data_percent"),
            ("total_functions", "matched_functions_percent"),
        ):
            if int(measures.get(total_key, 0)) and float(measures.get(percent_key, 0.0)) != 100.0:
                fail(f"{unit['name']}: marked complete without a 100% {percent_key}")


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: check_objdiff_report.py REPORT")
    report = json.loads(Path(sys.argv[1]).read_text(encoding="utf-8"))
    measures = report["measures"]
    total_code = int(measures.get("total_code", 0))
    total_data = int(measures.get("total_data", 0))
    if total_code + total_data != EXPECTED_ROM_SIZE:
        fail(f"coverage is 0x{total_code + total_data:X}, expected 0x{EXPECTED_ROM_SIZE:X}")
    if total_code != EXPECTED_CODE:
        fail(f"code size is {total_code}, expected {EXPECTED_CODE}")
    if total_data != EXPECTED_DATA:
        fail(f"data size is {total_data}, expected {EXPECTED_DATA}")
    if int(measures.get("total_functions", 0)) != EXPECTED_FUNCTIONS:
        fail("function count changed without updating the reviewed inventory")
    if int(measures.get("total_units", 0)) != EXPECTED_UNITS:
        fail("unit count changed without updating the reviewed inventory")

    for owner in [report, *report["categories"], *report["units"]]:
        owner_measures = owner["measures"]
        for key, value in owner_measures.items():
            if key.endswith("_percent") and not 0.0 <= float(value) <= 100.0:
                fail(f"{owner.get('name', owner.get('id', 'project'))}: invalid {key}")
        dimensions = (
            ("total_code", ("matched_code_percent", "complete_code_percent", "fuzzy_match_percent")),
            ("total_data", ("matched_data_percent", "complete_data_percent")),
            ("total_functions", ("matched_functions_percent",)),
        )
        for total_key, percentage_keys in dimensions:
            total = int(owner_measures.get(total_key, 0))
            for percentage_key in percentage_keys:
                if not total and percentage_key in owner_measures:
                    fail(
                        f"{owner.get('name', owner.get('id', 'project'))}: "
                        f"{percentage_key} has a zero denominator"
                    )

    validate_complete_units(report)

    print(
        f"objdiff report verified: {len(report['units'])} units, "
        f"{total_code} code bytes, {total_data} data bytes, 0x1000000 total"
    )


if __name__ == "__main__":
    main()
