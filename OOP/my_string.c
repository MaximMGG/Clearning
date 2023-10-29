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
