#include "core.h"

#define sqrt(a) a * a

int main() {


    #ifdef sqrt
        printf("%f\n", sqrt(2.5));
    #elif
        //
    #else
        #error no macro
    #endif

    return 0;
}


//#define
//#undef
//#ifdef
//#elif
//#else
//#endif
