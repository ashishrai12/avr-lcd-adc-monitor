import matplotlib.pyplot as plt
import numpy as np

def calculate_sensor_value(adc_val):
    return ((adc_val / 255.0) * 5.0) * 100.0

def plot_adc_response():
    # Generate all possible 8-bit ADC values (0-255)
    adc_values = np.arange(0, 256)
    sensor_values = [calculate_sensor_value(x) for x in adc_values]

    plt.figure(figsize=(10, 6))
    plt.plot(adc_values, sensor_values, label='Transfer Function')
    
    plt.title('ADC Value vs Calculated Sensor Output')
    plt.xlabel('ADC Value (8-bit)')
    plt.ylabel('Calculated Value (Virtual Units)')
    plt.grid(True)
    plt.legend()
    
    # Save the plot
    plt.savefig('adc_response_curve.png')
    print("Plot saved as adc_response_curve.png")

if __name__ == "__main__":
    plot_adc_response()
