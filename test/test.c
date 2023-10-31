#include <stdlib.h>
#include <stdio.h>


char get_char(int a) {
    switch (a) {
        case 0:
            return '0';
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        default:
            return '9';
    }
}


int main() {
    
    char *str_num = malloc(sizeof(char) * 12);
    unsigned char index = 0;

    int a = 1345676;

    int billions = 1000000000;
    int millions_100 = 100000000;
    int millions_10 = 10000000;
    int millions_1 = 1000000;
    int southends_100 = 100000;
    int southends_10 = 10000;
    int southends_1 = 1000;
    int hadreds_100 = 100;
    int hadreds_10 = 10;

    int buf;

    if ((buf = a / billions) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % billions;
    } 
    if ((buf = a / millions_100) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % millions_100;
    }
    if ((buf = a / millions_10) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % millions_10;
    }
    if ((buf = a / millions_1) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % millions_1;
    }
    if ((buf = a / southends_100) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % southends_100;
    }
    if ((buf = a / southends_10) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % southends_10;
    }
    if ((buf = a / southends_1) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % southends_1;
    }
    if ((buf = a / hadreds_100) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % hadreds_100;
    }
    if ((buf = a / hadreds_10) > 0) {
        str_num[index] = get_char(buf);
        index++;
        a = a % hadreds_10;
    }
    if (a > 0) {
        str_num[index] = get_char(a);
    }


    printf("%s\n", str_num);

    return 0;
}

