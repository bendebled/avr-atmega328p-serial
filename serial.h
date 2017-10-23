#ifndef SERIAL_H_
#define SERIAL_H_

    #define F_CPU 16000000UL

    void USART_init(int b);
    unsigned char USART_receive(void);
    void USART_sendchar(unsigned char data);
    void USART_sendstring(char* StringPtr);

#endif