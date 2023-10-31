#include <stdlib.h>
#include "my_string.h"
#include <stdio.h>


char * set_string(const char *s) {

}

m_string *cr_str(char *s) {
    m_string *p_s = malloc(sizeof(*p_s));
    m_strcpy(p_s, s);

    p_s->fm_strcpy = m_strcpy;
    return p_s;
}

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

void * m_strcpy(m_string *target, char *s) {
    target->str = malloc(sizeof(char) * (str_length(s)));
    if (target->str == NULL) {
        return NULL;
    }

    int length = 0;

    for(int i = 0; ; i++){
        target->str[i] = s[i];
        if (s[i] == '\0') {
            target->str[i] = '\0';
            length = i;
            break;
        }
    }
    target->length = length;
    return target->str;
}

char * str_cpy(char *target, char *buf) {
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
    printf("%ld, %ld", a, b);
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
    tt = str_cpy(tt, buf);
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
                    s = str_cpy(s, temp);
                    break;
            }
        }

    }
    va_end(li);
    return s;
}

