#include "adc.h"
//
//int16  adc1=0,adc2=0,adc3=0,adc4=0;
void ADC_ALL_init(void)
{
    adc_init(ADC_0, ADC0_CH10_A10 );
    adc_init(ADC_0, ADC0_CH12_A12);
    adc_init(ADC_1, ADC1_CH0_A16);
    adc_init(ADC_1, ADC1_CH4_A20);
}

void adcg(int16 * AD)
{
   AD[0]=adc_convert(ADC_0, ADC0_CH10_A10, ADC_12BIT);
   // AD[0]= adc_mean_filter(ADC_0, ADC0_CH10_A10, ADC_12BIT, 5);
   // AD[1]=adc_convert(ADC_0, ADC0_CH12_A12, ADC_12BIT);

    AD[1]=adc_convert(ADC_0, ADC0_CH12_A12, ADC_12BIT);
  //  AD[1]= adc_mean_filter(ADC_1, ADC1_CH0_A16, ADC_12BIT, 5);
 //   AD[2]=adc_convert(ADC_1, ADC1_CH4_A20, ADC_12BIT);
}

