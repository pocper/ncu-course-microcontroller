#include <stdio.h>
#include "c4mlib.h"

int input(){
    DIO_fpt(200, 0xff, 0, 0x0f); //DDRA setting
    DIO_fpt(4, 0x18, 3, 1);//portE3:4 sending H,L
    int data = 0, value[4] = {0x08, 0x04, 0x02, 0x01}, num[3][4] = {{0, 1, 4, 7}, {10, 2, 5, 8}, {10, 3, 6, 9}};
    while (1){
        for (int i = 0; i < 4; i++){
            DIO_fpt(1, 0x70, 4, 0x07);//portB sending O0 為H//Inverter L
            DIO_fpt(0, 0x0f, 0, value[3 - i]); //portA0:3 分別 sending H
            DIO_fpt(1, 0x70, 4, 0); //CLK改變
            DIO_fgt(100, 0xf0, 4, &data);
            if (data != 0){
                for (int j = 0; j < 4; j++){
                    if (data == value[j] && (i == 0 || (i > 0 && j != 0))){
                        return num[i][j];
                    }
                }
            }
        }
        _delay_ms(500);
    }
}

void output(int i, int num){
    DIO_fpt(200, 0xff, 0, 0xff); //DDRA setting
    DIO_fpt(4, 0x18, 3, 0x03);   //portE3:4 sending H,H
    DIO_fpt(1, 0x70, 4, 0x07);   //portB4:6 sending O1:4為H
    int number[10] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x0, 0x04};
    DIO_fpt(0, 0xff, 0, number[num]); //印出數字
    DIO_fpt(1, 0x70, 4, i); //portB O1:4分別為L
    DIO_fpt(1, 0x70, 4, 0x07); //portB4:6 sending O2:4為H
}

int main(){
    C4M_DEVICE_set();
    DIO_fpt(201, 0xff, 0, 0xff); //DDRB setting
    DIO_fpt(204, 0xff, 0, 0xff); //DDRE setting
    char seq[4][10] = {"first", "second", "third", "forth"};
    int move[4] = {0};
    for (int i = 0; i < 4; i++){
        printf("Enter %s number by keyboard\n", seq[i]);
        printf("print %d\n", input());
        move[3] = input();
        for (int j = 4; j > (3 - i); j--){
            output(j, move[j - 1]);
        }
        move[0] = move[1];
        move[1] = move[2];
        move[2] = move[3];
        _delay_ms(1000);
    }
    return 0;
}
