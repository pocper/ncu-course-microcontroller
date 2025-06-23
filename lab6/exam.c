#include "c4mlib.h"

char ExtPort_get(void)
{
    char data;

    DIO_fpt(201, 0xff, 0, 0xff); //DDRB setting
    DIO_fpt(204, 0xff, 0, 0xff); //DDRE setting
    DIO_fpt(202, 0xff, 0, 0x0);  //DDRC setting

    DIO_fpt(1, 0x70, 4, 0x00);    //portB sending //O0 result L //O1 result H
    DIO_fpt(4, 0x08, 3, 0x01);    //PE3 sending //result G L
    DIO_fpt(4, 0x10, 4, 0x01);    //PE4 sending //result Clock H
    DIO_fgt(102, 0xff, 0, &data); //portC getting

    return data;
}

char ExPort_put(char data)
{

    DIO_fpt(204, 0xff, 0, 0xff); //DDRE setting
    DIO_fpt(202, 0xff, 0, 0xff); //DDRC setting

    DIO_fpt(2, 0xff, 0, (int)data); //portC sending
    DIO_fpt(4, 0x08, 3, 0x0);       //PE3 sending //result G H
    DIO_fpt(4, 0x10, 4, 0x0);       //PE4 sending //result Clock L

    return 0;
}

int main()
{
    C4M_DEVICE_set();
    char a;
    while (1)
    {
        a = ExtPort_get();
        printf("0X%2x\n", (int)a);
        ExPort_put(a);
        _delay_ms(500);
    }
    return 0;
}