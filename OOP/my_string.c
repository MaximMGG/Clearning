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
    char *buf = malloc(sizeof(char *));

    for(int i = 0; s[i] != '\0'; i++){
        if (s[i] == '%') {
            switch(s[i + 1]) {
                case 's':
                    buf = va_arg(li, char *);
                    char *temp = insertString(s, buf, i);
                    s = _str_cpy(s, temp);
                    break;
            }
        }

    }
    va_end(li);
    return s;
}

