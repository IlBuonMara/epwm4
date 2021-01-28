/*
 * 
 Questo programma utilizza il modulo epwm1 con tmr2 per modulare 
 il segnale collegato ai led RB3, RB5, RB6, RB7
 per modulare rb3 è necessario premere contemporaneamente RA2 e RA4
 * 
 */


#include "mcc_generated_files/mcc.h"

void main(void)
{
SYSTEM_Initialize(); //Inizializzazione Del Microcontrollore while (1)
EPWM1_Initialize(); //inizializzazione del moduo epwm1
{
    RB3_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
    RB5_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
    RB6_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
    RB7_SetLow(); //Per poter modulare il segnale è necessario che il pin sia basso
    

while(IO_RA2_GetValue()==1 && IO_RA4_GetValue()==0){
    PSTR1CON = 0x02; //PWM Solo Su Bit 5 PORTB (0x02 attiva il pwm sul pin RB5)
    EPWM1_LoadDutyValue(0); //Duty 0%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(99); //Duty 20%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(199); //Duty 40%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(299); //Duty 60%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(399); //Duty 80%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(499); //Duty 100%
    __delay_ms(500); //Aspetto 500ms
    }
    
while(IO_RA3_GetValue()==1){
    PSTR1CON = 0x04; //PWM Solo Su Bit 6 PORTB (0x04 attiva il pwm sul pin RB6)
    EPWM1_LoadDutyValue(499); //Duty 100%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(399); //Duty 80%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(299); //Duty 60%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(199); //Duty 40%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(99); //Duty 20%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(0); //Duty 0%
    __delay_ms(500); //Aspetto 500ms
    }
    
    while(IO_RA4_GetValue()==1 && IO_RA2_GetValue()==0){
    PSTR1CON = 0x08; //PWM Solo Su Bit 7 PORTB (0x08 attiva il pwm sul pin RB7)
    EPWM1_LoadDutyValue(0); //Duty 0%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(99); //Duty 20%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(199); //Duty 40%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(299); //Duty 60%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(399); //Duty 80%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(499); //Duty 100%
    __delay_ms(500); //Aspetto 500ms
    }
    
while(IO_RA2_GetValue()==1 && IO_RA4_GetValue()==1){
    PSTR1CON = 0x01; //PWM Solo Su Bit 3 PORTB (0x01 attiva il pwm sul pin RB3)
    EPWM1_LoadDutyValue(499); //Duty 100%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(399); //Duty 80%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(299); //Duty 60%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(199); //Duty 40%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(99); //Duty 20%
    __delay_ms(500); //Aspetto 500ms
    EPWM1_LoadDutyValue(0); //Duty 0%
    __delay_ms(500); //Aspetto 500ms
    }
    
}
}