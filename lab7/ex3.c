#include <stdio.h>
#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();
    DIO_fpt(200, 0xff, 0, 0x0f);

    int row = 0, column = 0, num[16] = {'0', '1', '4', '7', 'A', '2', '5', '8', 'B', '3', '6', '9', 'F', 'E', 'D', 'C'};

    while (1)
    {
        for (int i = 0; i < 4; i++)
        { //列

            column = 0;
            column = 0x01 << i;
            DIO_fpt(0, 0x0f, 0, column); //列

            for (int j = 0; j < 4; j++)
            { //行

                DIO_fgt(100, 0xf0, (7 - j), &row); //行

                if (row == 1)
                {

                    printf("%c\n", num[i * 4 + j]);

                    _delay_ms(3000);
                }
            }
        }
    }
    return 0;
}