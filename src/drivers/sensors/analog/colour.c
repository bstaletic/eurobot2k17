#include <drivers/sensors/analog/colour.h>

uint16_t read_sensor()
{
	uint8_t channel[1] = {ADC1_CHANNEL};
	adc_set_regular_sequence(ADC1, 1, channel);
	adc_start_conversion_regular(ADC1);
	while (!adc_eoc(ADC1));
	return adc_read_regular(ADC1);
}
