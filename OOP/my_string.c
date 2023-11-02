#include "my_string.h"
#include <stdio.h>

unsigned int str_length(char *buf) {
    unsigned int length = 0;
    for(int i = 0; ; i++) {
        if (buf[i] == '\0') {
            length = i;
            break;
        }
    }
    return length;
}

char getCharFromInt(int tmp) {
    switch(tmp) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default: 
            return '0';
    }
}

int ** getPacOfDicimal() {
    int **buf = malloc(sizeof(int *) * 9);
    for(int i = 0; i < 9; i++) {
        buf[i] = malloc(sizeof(int));
    }
    *(buf[0]) = BIL;
    *(buf[1]) = MIL_100;
    *(buf[2]) = MIL_10;
    *(buf[3]) = MIL;
    *(buf[4]) = SOU_100;
    *(buf[5]) = SOU_10;
    *(buf[6]) = SOU;
    *(buf[7]) = HAN_100;
    *(buf[8]) = HAN_10;
    return buf;
}

char * mapIntToString(int buf) {

    char *s = malloc(sizeof(char) * 10);
    int s_index = 0;
    int tmp;
    int **num = getPacOfDicimal();

    for(int i = 0; i < 10;i++) {
        if ((tmp = buf / *(num[i])) > 0) {
            s[s_index] = getCharFromInt(tmp);
            s_index++;
            buf = buf % *(num[i]);
        } else if (tmp == 0) {
            if (s_index != 0) {
                s[s_index] = getCharFromInt(tmp);
                s_index++;
                buf = buf % *(num[i]);
            }
        }
    }
    return s;
}

char * str_set(char *s) {
    char *buf = malloc(sizeof(char) * str_length(s));
    for(int i = 0; ; i++) {
        if (s[i] == '\0') {
            buf[i] = '\0';
            break;
        }
        buf[i] = s[i];
    }
    return buf;
}

str *cr_str(char *s) {
    str *p_s = malloc(sizeof(*p_s));
    p_s->str = str_set(s);
    p_s->length = str_length(s);
    return p_s;
}

void * str_cpy(str *to, str *from) {
    to->str = realloc(to, sizeof(char) * (str_length(from->str)));
    if (to->str == NULL) {
        return NULL;
    }

    int length = 0;

    for(int i = 0; ; i++){
        if ((from->str[i] = '\0')) {
            to->str[i] = '\0';
            to->length = i;
            break;
        }
    }
    to->length = length;
    return to;
}

char * _str_cpy(char *target, char *buf) {
    target = malloc(sizeof(char) * str_length(buf));

    for(int i = 0; ; i++) {
        if (buf[i] == '\0') {
            target[i] = '\0';
            break;
        }
        target[i] = buf[i];
    }
    return target;
}


char * insertString(char *s, char *tmp, int pos){
    long a = sizeof(char) * (str_length(s));
    long b = sizeof(char) * (str_length(tmp));
    char *buf = malloc(a + b);
    int index;

    for(index = 0; index < pos; index++){
        buf[index] = s[index];
    }
    
    for(int i = 0; tmp[i] != '\0'; i++, index++){
        buf[index] = tmp[i];
    }

    for(int i = pos + 2; ; i++, index++){
        if (s[i] == '\0') {
            buf[index] = '\0';
            break;
        }
        buf[index] = s[i];
    }
    char * tt;
    tt = _str_cpy(tt, buf);
    free(buf);
    return tt;
}


char * str_format(char *s,...) {
    va_list li;
    va_start(li, s);
    char *buf_s = malloc(sizeof(char *));
    int buf_i;

    for(int i = 0; s[i] != '\0'; i++){
        if (s[i] == '%') {
            switch(s[i + 1]) {
                case 's':
                    buf_s = va_arg(li, char *);
                    char *temp_s = insertString(s, buf_s, i);
                    s = _str_cpy(s, temp_s);
                    break;
                case 'd':
                    buf_i = va_arg(li, int);
                    char *temp_i = insertString(s, mapIntToString(buf_i), i);
                    s = _str_cpy(s, temp_i);
            }
        }

    }
    va_end(li);
    return s;
}

void str_distroy(str *s) {
    free(s);
}

