#include <util/delay.h>
#include "serial.h"

int main(void){
    USART_init(9600);
     
    while(1){
        USART_sendstring("Hello world!\n");
        _delay_ms(1000);
    }
     
    return 0;
}