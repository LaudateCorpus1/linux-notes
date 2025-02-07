#ifndef INITS_H_
#define INITS_H_
#include "board.h"
//#include <adc_func.h>
#define PORT(n) (n)
#define PIN(n) (n)
#define HSADC_CLOCK_RATE 80000000 //80MSps
#define WDT_INTERVAL 0xFFFFFF //0xFF - min 0xFFFF - max
//Functions Declarations
void Timers_Init(int);
void GPIO_init(void);
void WDT_init(void);
void HSADC_init(void);
////////Functions///////////////
//Timer0 initialization function
void Timers_Init(int freqmatch0){
uint32_t timerFreq;
    Chip_TIMER_Init(LPC_TIMER0); //Timer 0 Init
    Chip_RGU_TriggerReset(RGU_TIMER0_RST);
    //Reset and clock settings
    while (Chip_RGU_InReset(RGU_TIMER0_RST)) {}
    timerFreq = Chip_Clock_GetRate(CLK_MX_TIMER0);
    //Timer0 Matching MR0 settings (TIMER1_HZ)
    Chip_TIMER_Reset(LPC_TIMER0);
    Chip_TIMER_MatchEnableInt(LPC_TIMER0, 0);
    Chip_TIMER_SetMatch(LPC_TIMER0, 0, (timerFreq / freqmatch0));
    Chip_TIMER_ResetOnMatchEnable(LPC_TIMER0, 0);
    Chip_TIMER_Enable(LPC_TIMER0);
//IRQ enables
    NVIC_EnableIRQ(TIMER0_IRQn);
    NVIC_ClearPendingIRQ(TIMER0_IRQn);
}
//Init of GPIO pins
void GPIO_init(void){
    Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, PORT(1), PIN(0));
    Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, PORT(1), PIN(1));
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, PORT(1), PIN(0), false);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, PORT(1), PIN(1), false);
}
/*Init WatchDog Timer reset mode*/
void WDT_init(void){
    Chip_WWDT_Init(LPC_WWDT);
    Chip_WWDT_SetTimeOut(LPC_WWDT, WDT_INTERVAL);
    Chip_WWDT_SetOption(LPC_WWDT, WWDT_WDMOD_WDRESET | WWDT_WDMOD_WDEN);
    Chip_WWDT_Feed(LPC_WWDT);
}
void HSADC_init(void){
//Frequency settings, ADC enable
 //   setupClock(HSADC_CLOCK_RATE);
//    setadcCLK();
    Chip_HSADC_Init(LPC_ADCHS);
//Config FIFO. (umbral de 15 muestras, empaquetadas de 2 en 2 enun word (4+12 + 4+12)
    Chip_HSADC_SetupFIFO(LPC_ADCHS, 15, true);
//Trigger por software para pruebas (modificar para permitir trg externo)
    Chip_HSADC_ConfigureTrigger(LPC_ADCHS, HSADC_CONFIG_TRIGGER_SW,
    HSADC_CONFIG_TRIGGER_RISEEXT, HSADC_CONFIG_TRIGGER_NOEXTSYNC,
    HSADC_CHANNEL_ID_EN_ADD, 0x90);
    Chip_HSADC_SetACDCBias(LPC_ADCHS, 0, HSADC_CHANNEL_DCBIAS,
    HSADC_CHANNEL_NODCBIAS);
//Se definen lindares de nivel para los registros A y B (provocaninterrupciones) (no uso)
    Chip_HSADC_SetThrLowValue(LPC_ADCHS, 0, ((HSADC_MAX_SAMPLEVAL*1)/10));
    Chip_HSADC_SetThrHighValue(LPC_ADCHS, 0,((HSADC_MAX_SAMPLEVAL*9)/10));
    Chip_HSADC_SetThrLowValue(LPC_ADCHS, 1, ((HSADC_MAX_SAMPLEVAL*4)/10));
    Chip_HSADC_SetThrHighValue(LPC_ADCHS, 1,((HSADC_MAX_SAMPLEVAL*6)/10));
//Set Power dependiendo de la Frecuencia y enable del ADC
    Chip_HSADC_SetPowerSpeed(LPC_ADCHS, false);
    Chip_HSADC_EnablePower(LPC_ADCHS);
//Descriptor settings. (por ahora dos descriptores)
    Chip_HSADC_SetupDescEntry(LPC_ADCHS, 0, 0, (HSADC_DESC_CH(0) |
    HSADC_DESC_HALT |
//HSADC_DESC_HALT |
    HSADC_DESC_MATCH(159) |
//Srate = (80/(delay+1))
    HSADC_DESC_RESET_TIMER));
    Chip_HSADC_EnableInts(LPC_ADCHS, 0, (HSADC_INT0_DSCR_DONE |
    HSADC_INT0_DSCR_ERROR));
//Enable ADC interrupt y update de descriptors.
//NVIC_EnableIRQ(ADCHS_IRQn);
    Chip_HSADC_UpdateDescTable(LPC_ADCHS, 0);
    Chip_HSADC_UpdateDescTable(LPC_ADCHS, 1);
}
#endif /* INITS_H_ */
