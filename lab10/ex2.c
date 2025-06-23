#include <stdio.h>
#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();

    AsaKb00Para_t KB = ASA_KB00_PARA_INI;  //KBOO 資料結構初始化
    Asa7s00Para_t LED = ASA_7S00_PARA_INI; //7S00資料結構初始化
    ASA_KB00_set(1, 200, 0xff, 0, 1, &KB);

    ASA_KB00_set(1, 202, 0xff, 0, 61, &KB); //E -45//F +43
    ASA_KB00_set(1, 203, 0xff, 0, 47, &KB); //D *42
    ASA_KB00_set(1, 204, 0xff, 0, 42, &KB); //C /47
    ASA_KB00_set(1, 205, 0xff, 0, 45, &KB); //B cls
    ASA_KB00_set(1, 209, 0xff, 0, 43, &KB); //A =61

    char get, num[4] = {0}, code;
    printf("start!\n");
    while (1)
    {
        ASA_KB00_get(1, 100, 1, &get, &KB);

        if (get != 1)
        {
            printf("Press %d\n", get);
            num[3] = num[2];
            num[2] = num[1];
            num[1] = num[0];
            num[0] = get;
            ASA_7S00_put(2, 0, 4, num, &LED);

            code = ASA_KB00_get(1, 100, 1, &get, &KB);
            while (get != 1)
            {
                ASA_KB00_get(1, 100, 1, &get, &KB);
            }
        }
        if (code != 0)
        {
            printf("error code %d\n", code);
        }
    }
    return 0;
}