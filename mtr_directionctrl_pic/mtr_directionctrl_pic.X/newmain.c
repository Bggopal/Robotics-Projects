
#include <xc.h>

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000

#define SW RD7
#define ENA RB0
#define ENB RB5
#define MTR_1 RB1
#define MTR_2 RB2
#define MTR_3 RB3
#define MTR_4 RB4

void main ()
{
    TRISD = 0x80;
    TRISB = 0x00;
    SW = 1;
    ENA= 0;
    ENB= 0;
    MTR_1 = 0;
    MTR_2 = 0;
    while(1)
    {
        ENA = 1;
        ENB = 1;
        if (SW == 1)
        {
            MTR_1 = 1; MTR_2 = 0;
            MTR_3 = 0; MTR_4 = 1;
        }
        else{
            MTR_1 = 0; MTR_2 = 1;
            MTR_3 = 1; MTR_4 = 0;
        }
    }
}
