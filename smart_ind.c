
#include <LPC21xx.H>
#include "header.h"
#include <stdio.h>

#define c ((IOPIN0 >> 14) & 1) //fire sensor
#define c1 ((IOPIN0 >> 15) & 1) //PIR sensor/worker

#define Green   (1 << 17)
#define Red     (1 << 18)

int main(void)
{
    unsigned int a_value = 0;
    float vout = 0.0;
    float temp = 0.0;
    char a[30];

// LED pins as output 
    IODIR0|= (Green | Red);

// Initialize peripherals
    lcd_init();
    uart_init(9600);
    adc_init();

    while (1)
    {
// Clear LCD 
        lcd_cmd(0x01);
        lcd_cmd(0x80);

// Temperature heading 
        uart_str("\r\n--:Temperature:--\r\n");

// Read temperature sensor through ADC channel 1 
        a_value = adc_read(1);

        vout = (a_value * 3.3) / 1023.0;
        temp = vout/0.01;

//Send temperature through UART 
        sprintf(a,"Temp:%.2f\r\n", temp);
        uart_str(a);

// Display temperature on LCD 
        lcd_str("Temp:");
        lcd_float(temp);

// FIRE //
        if (c==0)
        {
            sprintf(a, "Fire=YES\r\n");
            uart_str(a);
        }
        else
        {
            sprintf(a, "Fire=NO\r\n");
            uart_str(a);
        }

// PIR //
        if (c1==1)
        {
            sprintf(a, "Worker:YES\r\n");
            uart_str(a);
        }
        else
        {
            sprintf(a, "Worker:NO\r\n");
            uart_str(a);
        }

//STATUS//
        lcd_cmd(0xC0);

        if ((c1==1)||(c==0))
        {
            sprintf(a, "Status:Danger\r\nLED status:Red\r\n");
            uart_str(a);

            IOSET0 = Green;
            IOCLR0 = Red;

            lcd_str("Status:Danger");
        }
        else
        {
            sprintf(a, "Status:SAFE\r\nLED status:Green\r\n");
            uart_str(a);

            IOSET0 = Red;
            IOCLR0 = Green;

            lcd_str("Status:SAFE");
        }

        delay_ms(1000);
    }
}
