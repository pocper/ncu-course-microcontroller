#include "c4mlib.h"

AsaKb00Para_t KB = ASA_KB00_PARA_INI; //KBOO 資料結構初始化

int sec1_100 = 0;

ISR(TIMER2_COMP_vect) //計時模組
{
    sec1_100++;
}

int main()
{
    C4M_DEVICE_set();

    TIM_fpt(222, 0x07, 0, 5); //除頻設定選用 N=256
    TIM_fpt(222, 0x48, 3, 1); //設定計時方式 CTC
    TIM_fpt(207, 0x80, 7, 1); //開啟 TIM2 中斷
    unsigned char ocr2 = 53;  //f oc2=100=11059200/2*256/(1+ocr2)
    TIM_put(10, 1, &ocr2);    //設定CTC週期 OCR2=215 f=100
    sei();
    ASA_KB00_set(1, 200, 0xff, 0, 1, &KB);
    DIO_fpt(200, 0x0f, 0, 0xff);

    int i = 0, press = 1, inverse = 1, rate = 5, in = 0;
    int seq[8] = {0x07, 0x03, 0x0b, 0x09, 0x0d, 0x0c, 0x0e, 0x06};

    while (1)
    {
        if (sec1_100 >= rate)
        {
            DIO_fpt(0, 0x0f, 0, seq[i]);
            sec1_100 = 0;

            i += inverse;

            if (i == 8 && inverse == 1)
            {
                i = 0;
            }
            else if (i == 0 && inverse == -1)
            {
                i = 8;
            }
        }

        ASA_KB00_get(1, 100, 1, &press, &KB);

        if (press != 1)
        {
            in += 1;

            if (in == 1)
            {
                switch (press)
                {
                case 48: //0 減速
                    rate += 1;
                    break;

                case 49: //1 加速
                    if (rate > 1)
                    {
                        rate -= 1;
                    }
                    else
                    {
                        rate = 1;
                    }
                    break;

                case 65: //A 逆轉
                    inverse = -1;
                    break;

                case 50: //2 順轉
                    inverse = 1;
                    break;

                case 69: // 跳出永久迴圈
                    return 0;
                }
                printf("press=%d inverse=%d rate=%d\n", press, inverse, rate);
            }
        }
        else
        {
            in = 0;
        }
    }

    return 0;
}
