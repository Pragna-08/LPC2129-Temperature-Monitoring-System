#ifndef HEADER_H
#define HEADER_H

/* Delay functions */
int delay_ms(unsigned int ms);
int delay_sec(unsigned int sec);

/* UART functions */
void uart_init(unsigned int baud);
void uart_tx(unsigned char data);
unsigned char uart_rx(void);
void uart_str(char *p);
void uart_tx_int(int num);
void uart_tx_float(float num);

/* ADC functions */
void adc_init(void);
unsigned int adc_read(unsigned int ch_num);

/* LCD functions */
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char cmd);
void lcd_init(void);
void lcd_str(char *p);
int lcd_len(char *p);
void lcd_int(int num);
void lcd_float(float num);

#endif
