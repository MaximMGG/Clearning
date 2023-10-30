#include <_mingw_stdarg.h>
#include <stdlib.h>
#include "my_string.h"


char * set_string(const char *s) {

}

m_string *cr_str(const char *s) {
    m_string *p_s = malloc(sizeof(*p_s));
    m_strcpy(p_s, s);
    p_s->fm_strcpy = m_strcpy;
    return p_s;
}

void * m_strcpy(m_string *target, const char *s) {
    target->str = malloc(sizeof(*s));
    if (target->str == NULL) {
        return NULL;
    }

    int length;

    for(int i = 0; ; i++){
        target->str[i] = s[i];
        if (s[i] == '\0') {
            length = i;
            break;
        }
    }

}

char * insertString(char *s, char *tmp, int pos){
    char *buf = malloc(sizeof(*s + *tmp));
    int index;
    for(index = 0; index < pos; index++){
        buf[index] = s[index];
    }
    
    for(int i = 0; tmp[i] != '\0'; i++, index++){
        buf[index] = tmp[i];
    }

    for(int i = pos + 2; s[i] != '\0'; i++, index++){
        buf[index] = s[i];
    }

    return buf;
}

char * str_format(char *s,...) {
    va_list li;
    va_start(li, s);

    for(int i = 0; s[i] != '\0'; i++){
        if (s[i] == '%') {
            switch(s[i + 1]) {
                case 's':
                    char *buf = va_arg(li, char *);
                    s = insertString(s, buf, i);
                    break;
            }
        }

    }
    va_end(li);
    return s;
}

