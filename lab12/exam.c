#include "c4mlib.h"

int sec1_1000 = 0;

ISR(TIMER2_COMP_vect) //計時模組
{
    sec1_1000++;
}

int main()
{
    C4M_DEVICE_set();

    TIM_fpt(222, 0x07, 0, 5); //除頻設定選用 N=256
    TIM_fpt(222, 0x48, 3, 1); //設定計時方式 CTC
    TIM_fpt(207, 0x80, 7, 1); //開啟 TIM2 中斷

    unsigned char ocr2 = 53; //f oc2=100=11059200/2*256/(1+ocr2)
    TIM_put(10, 1, &ocr2);   //設定CTC週期 OCR2=215 f=100
    sei();
    int i = 0;
    DIO_fpt(200, 0x0f, 0, 0xff);
    int seq[8] = {0x07, 0x03, 0x0b, 0x09, 0x0d, 0x0c, 0x0e, 0x06};
    while (1)
    {
        printf("%d %d\n", i, sec1_1000);

        if (sec1_1000 == 1)
        {
            DIO_fpt(0, 0x0f, 0, seq[i]);
            sec1_1000 = 0;
            i++;

            if (i == 8)
            {
                i = 0;
            }
        }
    }

    return 0;
}