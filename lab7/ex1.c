#include <stdio.h>
#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();
    DIO_fpt(202, 0xff, 0, 0xff);
    int count = 1;

    while (1)
    {

        DIO_fpt(2, 0xff, 0, count);

        count++;

        if (count >= 10)
        {

            count = 0;
        }

        _delay_ms(3000);
    }

    return 0;
}