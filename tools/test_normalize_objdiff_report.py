import unittest

from tools.normalize_objdiff_report import normalize


class NormalizeObjdiffReportTest(unittest.TestCase):
    def test_target_only_dimensions_are_zero_and_empty_dimensions_removed(self):
        report = {
            "measures": {},
            "units": [
                {
                    "name": "code",
                    "measures": {"total_code": "20", "total_functions": 2,
                                 "matched_data_percent": 100.0},
                    "sections": [{"name": ".text", "size": "20"}],
                    "metadata": {"progress_categories": ["game"]},
                },
                {
                    "name": "data",
                    "measures": {"total_data": "80", "matched_code_percent": 100.0},
                    "sections": [{"name": ".rodata", "size": "80"}],
                    "metadata": {"progress_categories": ["game"]},
                },
            ],
            "categories": [{"id": "game", "name": "Game", "measures": {}}],
        }
        normalize(report)
        code, data = report["units"]
        self.assertEqual(code["measures"]["matched_code_percent"], 0.0)
        self.assertEqual(code["measures"]["matched_functions_percent"], 0.0)
        self.assertNotIn("matched_data_percent", code["measures"])
        self.assertEqual(data["measures"]["matched_data_percent"], 0.0)
        self.assertNotIn("matched_code_percent", data["measures"])
        self.assertEqual(report["categories"][0]["measures"]["matched_code_percent"], 0.0)
        self.assertEqual(report["measures"]["matched_data_percent"], 0.0)

    def test_existing_match_values_are_weighted(self):
        report = {
            "measures": {},
            "units": [
                {"measures": {"total_code": "25", "matched_code_percent": 100.0}, "sections": [{"size": "25"}], "metadata": {}},
                {"measures": {"total_code": "75"}, "sections": [{"size": "75"}], "metadata": {}},
            ],
            "categories": [],
        }
        normalize(report)
        self.assertEqual(report["measures"]["matched_code_percent"], 25.0)

    def test_section_matched_anonymous_padding_is_counted_as_matched_data(self):
        report = {
            "measures": {},
            "units": [{
                "name": "libc/memcpy",
                "measures": {"total_code": "94", "matched_code_percent": 100.0},
                "sections": [{"name": ".text", "size": "96", "fuzzy_match_percent": 100.0}],
                "metadata": {},
            }],
            "categories": [],
        }
        normalize(report)
        measures = report["units"][0]["measures"]
        self.assertEqual(measures["total_data"], "2")
        self.assertEqual(measures["matched_data_percent"], 100.0)
        self.assertEqual(measures["complete_data_percent"], 100.0)


if __name__ == "__main__":
    unittest.main()
