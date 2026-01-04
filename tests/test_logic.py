import unittest

def calculate_sensor_value(adc_val):
    """
    Python implementation of the C function for testing logic.
    Formula: ((adc_val / 255.0) * 5.0) * 100.0
    """
    return ((adc_val / 255.0) * 5.0) * 100.0

class TestSensorLogic(unittest.TestCase):
    def test_min_value(self):
        """Test 0V input"""
        val = calculate_sensor_value(0)
        self.assertAlmostEqual(val, 0.0, places=2)

    def test_max_value(self):
        """Test ~5V input (255)"""
        val = calculate_sensor_value(255)
        self.assertAlmostEqual(val, 500.0, places=2)

    def test_mid_value(self):
        """Test ~2.5V input (128)"""
        val = calculate_sensor_value(128)
        # 128/255 * 5 * 100 = 0.5019 * 500 = 250.98
        self.assertAlmostEqual(val, 250.98, places=2)

if __name__ == '__main__':
    unittest.main()
