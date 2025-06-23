#include <stdio.h>
#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();

    AsaKb00Para_t KB = ASA_KB00_PARA_INI;  //KBOO 資料結構初始化
    Asa7s00Para_t LED = ASA_7S00_PARA_INI; //7S00資料結構初始化
    ASA_KB00_set(1, 200, 0xff, 0, 1, &KB);

    char get, num[4] = {0};
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

            ASA_KB00_get(1, 100, 1, &get, &KB);
            while (get != 1)
            {
                ASA_KB00_get(1, 100, 1, &get, &KB);
            }
        }
    }
    return 0;
}