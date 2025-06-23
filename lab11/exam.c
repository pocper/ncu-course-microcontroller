#include <stdio.h>
#include "c4mlib.h"

AsaKb00Para_t KB = ASA_KB00_PARA_INI;  //KBOO 資料結構初始化
Asa7s00Para_t LED = ASA_7S00_PARA_INI; //7S00資料結構初始化

int tempnewtime = 0, alermtime = 0;
int min = 0, sec = 0, sec1_100 = 0; //目前時間
int status = 0, set = 0;            //目前狀態
char time[4] = {48, 48, 48, 48};    //僅顯示小時跟分鐘
char newtime[4] = {0};
int alermup = 0;

void keyboard(int set, char num) //0~9數字 A完畢 B放棄 C鬧鐘關閉 D設定進入時間 E進入設定鬧鐘
{

    if (num > 47 && num < 58) //A 65 B 66 C 67 D 68 E 69
    {
        newtime[3] = newtime[2];
        newtime[2] = newtime[1];
        newtime[1] = newtime[0];
        newtime[0] = num;
    }

    else if (num == 65) //A
    {
        if (set == 1)
        {
            min = tempnewtime / 100;
            sec = tempnewtime % 100;
        }

        else if (set == 2)
        {
            alermtime = tempnewtime;
        }

        tempnewtime = status = 0;

        for (int i = 0; i < 4; i++)
        {
            newtime[i] = 0;
        }
    }

    else if (num == 66) //B
    {
        tempnewtime = status = 0;

        for (int i = 0; i < 4; i++)
        {
            newtime[i] = 0;
        }

        ASA_7S00_put(2, 0, 4, time, &LED);
    }

    else if (num == 67) //C 鬧鐘關閉切換鍵
    {
        if (set == 3) //如果鬧鐘關閉
        {
            status = 4; //調整為時間未到

            if (alermup == 0)
            {
                alermup = 1;
            }
            else
            {
                alermup = 0;
            }
        }

        else if (set == 4 || set == 5) //如果時間未到或時間已到調整為鬧鐘關閉
        {
            status = 3;
        }

        // 1. 設定時鐘狀態
        // 2. 設定鬧鈴狀態
        // 3. 鬧鈴關閉狀態
        // 4. 時間未到狀態
        // 5. 時間己到狀態
    }

    if (newtime[3] != 0)
    {
        tempnewtime = 1000 * (newtime[3] - 48) + 100 * (newtime[2] - 48) + 10 * (newtime[1] - 48) + (newtime[0] - 48);
    }
    else if (newtime[2] != 0)
    {
        tempnewtime = 100 * (newtime[2] - 48) + 10 * (newtime[1] - 48) + (newtime[0] - 48);
    }
    else if (newtime[1] != 0)
    {
        tempnewtime = 10 * (newtime[1] - 48) + (newtime[0] - 48);
    }
    else if (newtime[0] != 0)
    {
        tempnewtime = newtime[0] - 48;
    }
}

void alerm() //鬧鈴模組
{
    printf("alerms up!\n");
    status = 5;
    output(status);
}

void output(int set) //顯示模組
{
    char blink[2] = {0, 15};

    if (set == 2 || set == 5) // E 設定鬧鐘 時鐘已到
    {
        ASA_7S00_set(2, 200, 0x0f, 0, blink[1], &LED); //四顆都閃爍 //這裡有問題 不能直接放 15
    }

    else // D 設定時鐘 C 鬧鐘關閉 時間未到
    {
        ASA_7S00_set(2, 200, 0x0f, 0, blink[0], &LED); //四顆都不閃爍
    }

    if (set == 1 || set == 2)
    {
        ASA_7S00_put(2, 0, 4, newtime, &LED);
    }
    else
    {
        ASA_7S00_put(2, 0, 4, time, &LED);
    }
}

ISR(TIMER2_COMP_vect) //計時模組
{
    sec1_100++;

    if (sec1_100 == 5574)
    {
        sec += 1;
        sec1_100 = 0;

        if (sec == 60)
        {
            min += 1;
            sec = 0;
        }
    }
}

int main()
{
    C4M_DEVICE_set();

    TIM_fpt(222, 0x07, 0, 3); //除頻設定選用 N=1024 //N=64
    TIM_fpt(222, 0x48, 3, 1); //設定計時方式 CTC
    TIM_fpt(207, 0x80, 7, 1); //開啟 TIM2 中斷

    unsigned char ocr2 = 30; //f oc2=100=11059200/2*64/(1+30) //
    TIM_put(10, 1, &ocr2);   //設定CTC週期 OCR2=215 f=100
    sei();

    int lastsec = 0; //ISR上一秒
    char press = 1;
    int in = 0, now = 0;

    printf("-----------start!-------------\n");
    ASA_KB00_set(1, 200, 0xff, 0, 1, &KB);
    ASA_7S00_set(2, 200, 0xf0, 6, 1, &LED); //分鐘及秒之間加小數點

    while (1)
    {
        now = 1000 * (time[3] - 48) + 100 * (time[2] - 48) + 10 * (time[1] - 48) + (time[0] - 48);

        if (now == alermtime && now != 0 && alermup == 1) //還沒確定
        {
            alerm();
        }

        if (sec != lastsec)
        {
            time[0] = (sec % 10) + 48;
            time[1] = (sec / 10) + 48;
            time[2] = (min % 10) + 48;
            time[3] = (min / 10) + 48;

            lastsec = sec;
        }

        ASA_KB00_get(1, 100, 1, &press, &KB); //通過這行 sec1_100要減5

        if (press != 1)
        {
            in++;

            if (press == 67) //C
            {
                status = 3;
            }

            if (press == 68) //D
            {
                status = 1;
            }

            else if (press == 69) //E
            {
                status = 2;
            }

            if (in == 1)
            {
                keyboard(status, press);
                printf("temp=%4d alerm=%4d alermup=%d\n", tempnewtime, alermtime, alermup);
            }
        }

        else
        {
            in = 0;
            output(status);
        }
    }

    return 0;
}