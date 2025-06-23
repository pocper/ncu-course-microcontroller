#include "c4mlib.h"

int inner[2] = {0}, outer[2] = {0};
int v = 300, denominator = 1, step = 200;
int get = 0;
int stop = 0;

void wheel(int n, int x) //n=1為左邊 2為右邊
{
    if (n == 1)
    {
        denominator = 1; // + 逆時針
    }

    else
    {
        denominator = -1; //- 順時針
    }

    if (x == 0)
    {
        denominator *= 1; // x=0 正常
    }
    else
    {
        denominator *= 0; // x=1 停止
    }

    ASA_SPIM_trm(101, n, 3, 2, &denominator, 10); //降速除頻
    _delay_ms(100);
}

void sensor()
{

    DIO_fgt(100, 0x0f, 0, &get); //0左一 1左二 2右三 3右四 //黑色是0 白色是1
    printf("%2d) ", get);
    outer[0] = (get >> 0) & 1;
    inner[0] = (get >> 1) & 1;
    inner[1] = (get >> 2) & 1;
    outer[1] = (get >> 3) & 1;
}

void condition()
{
    switch (get)
    {
    case 14:
        printf("向左大修正");
        wheel(1, 1);
        wheel(4, 0);
        _delay_ms(700);
        break;

    case 7:
        printf("向右大修正");
        wheel(1, 0);
        wheel(4, 1);
        _delay_ms(700);
        break;

    case 8:
    case 12:
        printf("向左小修正");
        wheel(1, 1);
        wheel(4, 0);
        _delay_ms(300);
        break;

    case 1:
    case 3:
        printf("向右小修正");
        wheel(1, 0);
        wheel(4, 1);
        _delay_ms(300);
        break;

    case 2:
    case 4:
    case 9:
    case 11:
    case 13:
        printf("直走");
        wheel(1, 0);
        wheel(4, 0);
        _delay_ms(200);
        break;

    case 0:
        printf("延遲直走");
        wheel(1, 0);
        wheel(4, 0);
        _delay_ms(15500);
        stop = 1;
        wheel(1, 1);
        wheel(4, 1);
        break;

    case 15:
        printf("延遲直走");
        break;

    default:
        printf("不可能");
        break;
    }

    printf("\n");
}

int main()
{
    C4M_DEVICE_set();
    ASA_SPIM_trm(101, 1, 1, 2, &v, 10); //設定最高速度
    ASA_SPIM_trm(101, 4, 1, 2, &v, 10);

    DIO_fpt(200, 0xff, 0, 0); //port A 全埠輸入

    wheel(1, 0); //兩邊正轉
    wheel(4, 0);

    while (1)
    {
        sensor();
        condition();
        if (stop == 1)
        {
            break;
        }
    }

    return 0;
}