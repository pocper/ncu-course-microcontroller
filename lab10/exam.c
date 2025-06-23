#include <stdio.h>
#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();

    AsaKb00Para_t KB = ASA_KB00_PARA_INI;  //KBOO 資料結構初始化
    Asa7s00Para_t LED = ASA_7S00_PARA_INI; //7S00資料結構初始化
    ASA_KB00_set(1, 200, 0xff, 0, 1, &KB);

    char get, num[4] = {0}, len = 0, blink[4] = {1, 2, 4, 8};
    char count = 0, reset[4] = {'0', 0, 0, 0}, press = 0;

    ASA_7S00_put(2, 0, 4, reset, &LED);

    printf("--------------start!--------------\n");

    while (1)
    {
        ASA_KB00_get(1, 100, 1, &get, &KB);

        if (get != 1)
        {
            printf("get=%c len=%d count=%d\n", get, len, count);

            if (get > 47 && get < 58)
            {
                num[3] = num[2];
                num[2] = num[1];
                num[1] = num[0];
                num[0] = get;
                ASA_7S00_put(2, 0, 4, num, &LED);

                if (press == 1)
                {
                    if (count == 4)
                    {
                        press = count = 0;
                        ASA_7S00_set(2, 200, 0xf0, 4, 0, &LED);
                    }
                    else
                    {
                        count++;
                        ASA_7S00_set(2, 200, 0xf0, 4, blink[count - 1], &LED);
                    }
                }
            }

            else if (get == 65 || get == 66)
            {
                if (get == 65) //閃爍
                {
                    if (len == 4)
                    {
                        len = 0;
                        ASA_7S00_set(2, 200, 0x0f, 0, 0, &LED);
                    }
                    else
                    {
                        len++;
                        ASA_7S00_set(2, 200, 0x0f, 0, blink[len - 1], &LED);
                    }
                }
                else //小數
                {
                    press = count = 1;
                    ASA_7S00_set(2, 200, 0xf0, 4, blink[count - 1], &LED);
                }
            }

            ASA_KB00_get(1, 100, 1, &get, &KB);
            while (get != 1)
            {
                ASA_KB00_get(1, 100, 1, &get, &KB);
            }
        }
    }

    return 0;
}