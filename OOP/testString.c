#include <assert.h>
#include <stdio.h>
#include "my_string.h"


void testStringCompare() {
    str* sameOne = cr_str("Bobby");
    str* sameTwo = cr_str("Bobby");

    str* notSame = cr_str("Molly");

    assert(str_cmp(sameOne, sameTwo));
    assert(!str_cmp(sameOne, notSame));
}



void testStringConcat() {
    str *one = cr_str("Hello");
    str *two = cr_str("World!");
    str *tree = str_concat(one, two, ' ');

    str *buf = cr_str("Hello World!");

    assert(str_cmp(tree, buf));
}



int main() {

    puts("Test comparing string!");
    testStringCompare();
    puts("Test comparing string! -> success");
    puts("----------------------------------------------------");
    puts("Test string concat");
    testStringConcat();
    puts("Test string concat -> success");
    puts("----------------------------------------------------");

    return 0;
}
