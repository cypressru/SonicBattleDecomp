#!/usr/bin/env python3
"""Make objdiff progress percentages truthful for target-only units.

objdiff reports an empty dimension as 100% (for example, code progress on a
data-only object) and may omit the measured dimension when no comparable base
section exists.  decomp.dev consumes those values verbatim.  Normalize each
unit, then recompute category and project percentages from byte/function
weights so an unmatched target section is shown as 0%, not 100%.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path


DIMENSIONS = {
    "code": ("total_code", ("matched_code_percent", "complete_code_percent", "fuzzy_match_percent")),
    "data": ("total_data", ("matched_data_percent", "complete_data_percent")),
    "functions": ("total_functions", ("matched_functions_percent",)),
}


def amount(measures: dict[str, object], key: str) -> int:
    return int(measures.get(key, 0))


def normalize_unit(unit: dict[str, object]) -> None:
    measures = unit.setdefault("measures", {})
    assert isinstance(measures, dict)
    section_total = sum(int(section["size"]) for section in unit.get("sections", []))
    measured_total = amount(measures, "total_code") + amount(measures, "total_data")
    if section_total < measured_total:
        raise ValueError(f"{unit.get('name', 'unit')}: measures exceed owned sections")
    if section_total > measured_total:
        # Mapping-symbol padding is owned non-code data even when objdiff does
        # not emit a symbol-derived total for it.
        measures["total_data"] = str(
            amount(measures, "total_data") + section_total - measured_total
        )
        full_section_match = all(
            float(section.get("fuzzy_match_percent", 0.0)) == 100.0
            for section in unit.get("sections", [])
        )
        if full_section_match:
            # objdiff's section-level comparison includes anonymous alignment
            # bytes even though its symbol-derived data totals omit them.
            measures["matched_data_percent"] = 100.0
            measures["complete_data_percent"] = 100.0
        elif not unit.get("metadata", {}).get("has_base", False):
            measures.pop("matched_data_percent", None)
            measures.pop("complete_data_percent", None)
    for total_key, percent_keys in DIMENSIONS.values():
        total = amount(measures, total_key)
        for percent_key in percent_keys:
            if total:
                measures.setdefault(percent_key, 0.0)
            else:
                measures.pop(percent_key, None)


def aggregate(units: list[dict[str, object]]) -> dict[str, object]:
    result: dict[str, object] = {"total_units": len(units)}
    for total_key, percent_keys in DIMENSIONS.values():
        total = sum(amount(unit["measures"], total_key) for unit in units)
        if not total:
            continue
        result[total_key] = str(total) if total_key != "total_functions" else total
        for percent_key in percent_keys:
            weighted = sum(
                amount(unit["measures"], total_key)
                * float(unit["measures"].get(percent_key, 0.0))
                for unit in units
            )
            result[percent_key] = weighted / total
    return result


def normalize(report: dict[str, object]) -> None:
    units = report["units"]
    categories = report["categories"]
    assert isinstance(units, list) and isinstance(categories, list)
    for unit in units:
        normalize_unit(unit)

    by_category: dict[str, list[dict[str, object]]] = {}
    for unit in units:
        metadata = unit.get("metadata", {})
        for category in metadata.get("progress_categories", []):
            by_category.setdefault(category, []).append(unit)
    for category in categories:
        category["measures"] = aggregate(by_category.get(category["id"], []))
    report["measures"] = aggregate(units)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("report", type=Path)
    args = parser.parse_args()
    report = json.loads(args.report.read_text(encoding="utf-8"))
    normalize(report)
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
