#include "core.h"




enum {
    BOLD = 0b0001,
    ITALIC = 0b0010,
    UNDERLINE = 0b0100
};


union {
    struct {
        unsigned char isBold : 1;
        unsigned char isItalic : 1;
        unsigned char IsUnderline : 1;
    };
    unsigned char flage;
} textParam;

#define BOLD       0b0001
#define ITALIC     0b0010
#define UNDERLINE  0b0100



void task();

int main() {

    // textParam.isBold = textParam.isItalic = textParam.IsUnderline = 1;
    textParam.flage = BOLD | ITALIC;

    if (textParam.isBold)
        printf("Text is bold\n");
    if (textParam.isItalic)
        printf("Text is italic\n");
    if (textParam.IsUnderline)
        printf("Text is underline\n");


    task();

    return 0;
}





enum {
    ONE = 0b0001,
    TWO = 0b0010,
    THREE = 0b0100,
    FOUR = 0b1000,
};


union {
    struct {
        unsigned char one : 1;
        unsigned char two : 1;
        unsigned char three : 1;
        unsigned char four : 1;
    };
    unsigned char FF;
}ff;




void task() {

    ff.FF = ONE | THREE;

    unsigned char flag = ONE | THREE;

    if (ff.one) 
        printf("ONE\n");
    if (ff.two) 
        printf("TWO\n");
    if (ff.three) 
        printf("THREE\n");
    if (ff.four) 
        printf("FOUR\n");
}

