import unittest

from check_objdiff_report import validate_complete_units


class CompleteUnitValidationTests(unittest.TestCase):
    def test_rejects_false_complete_unit(self):
        report = {
            "units": [{
                "name": "game/example",
                "metadata": {"complete": True},
                "measures": {"total_code": "4", "matched_code_percent": 0.0},
            }]
        }
        with self.assertRaisesRegex(SystemExit, "marked complete"):
            validate_complete_units(report)

    def test_allows_truthful_complete_unit(self):
        report = {
            "units": [{
                "name": "game/example",
                "metadata": {"complete": True},
                "measures": {"total_code": "4", "matched_code_percent": 100.0},
            }]
        }
        validate_complete_units(report)
