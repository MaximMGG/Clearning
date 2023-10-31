#include <stdlib.h>
#include <stdarg.h>


typedef struct m_string{
    char *str;
    unsigned int length;
    void * (*fm_strcpy) (struct m_string *str, char *s);
} m_string;

typedef struct {
    char * (*pset_string) (const char *s);
} m_setS;

m_string *cr_str(char *s);
char * set_string(const char *s);
void * m_strcpy(m_string *str, char *s);
char * str_format(char *s, ...);
