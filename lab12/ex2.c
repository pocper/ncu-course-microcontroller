#include "c4mlib.h"

int main()
{
    C4M_DEVICE_set();

    int data[3] = {500, 4096, 1};

    printf("start!\n");
    printf("Enter the value of speed=");
    scanf("%d", &data[0]);

    printf("Enter the step=");
    scanf("%d", &data[1]);

    printf("Enter the frequency eliminator=");
    scanf("%d", &data[2]);

    ASA_SPIM_trm(101, 3, 1, 2, &data[0], 10); //設定最高速度
    _delay_ms(500);

    ASA_SPIM_trm(101, 3, 2, 2, &data[1], 10); //指定移位步數
    _delay_ms(500);

    ASA_SPIM_trm(101, 3, 3, 2, &data[2], 10); //降速除頻
    _delay_ms(500);

    return 0;
}
