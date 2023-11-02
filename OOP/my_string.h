#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


typedef struct m_string{
    char *str;
    unsigned int length;
    void * (*fm_strcpy) (struct m_string *str, char *s);
} str;

typedef struct {
    char * (*pset_string) (const char *s);
} m_setS;

str *cr_str(char *s);
char * str_set(char *s);
void * str_cpy(str *to, str *from);
char * str_format(char *s, ...);


enum {
    BIL = 1000000000,
    MIL_100 = 100000000,
    MIL_10 = 10000000,
    MIL = 1000000,
    SOU_100 = 100000,
    SOU_10 = 10000,
    SOU = 1000,
    HAN_100 = 100,
    HAN_10 = 10
};


const int num[9] = {BIL, MIL_100, MIL_10, MIL, SOU_100, SOU_10, SOU, HAN_100, HAN_10};
