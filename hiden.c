#include <stdio.h>
#include <stdlib.h>


struct SPoint {
    int x, y;
};


struct SSize {
    int width, height;
};

struct SShape {
    char *name;
    struct SPoint;
    union {
        struct SSize;
        float radius;
    } size;
};

union U1 {
    int x;
    char arr[4];
};

int main() {
    

    struct SShape shape = {"quas", 10, 20, 0, 0};
    shape.size.radius = 55;
    printf("%s %d %d %f\n", shape.name, shape.x, shape.y, shape.size.radius);

    return 0;
}
