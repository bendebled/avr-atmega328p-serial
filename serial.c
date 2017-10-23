#include <avr/io.h>
#include "serial.h"

static int baudrate;
static int baud_prescaler;
 
void USART_init(int b){
    baudrate = b;
    baud_prescaler = (((F_CPU / (baudrate * 16UL))) - 1);

    UBRR0H = (uint8_t)(baud_prescaler>>8);
    UBRR0L = (uint8_t)(baud_prescaler);
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (3<<UCSZ00);
}
 
unsigned char USART_receive(void){
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}
 
void USART_sendchar(unsigned char data){
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}
 
void USART_sendstring(char* StringPtr){
    while(*StringPtr != 0x00) {
        USART_sendchar(*StringPtr);
        StringPtr++;
    }
}