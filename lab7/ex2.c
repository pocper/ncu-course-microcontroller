#include <stdio.h>
#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();
    DIO_fpt(202, 0xff, 0, 0xff);
    int count = 0, number[10] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x0, 0x04};

    while (1)
    {
        DIO_fpt(2, 0xff, 0, number[count]);
        count++;

        if (count > 9)
        {
            count = 0;
        }
        _delay_ms(3000);
    }
    return 0;
}