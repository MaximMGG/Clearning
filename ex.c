
#include <stdio.h>


int main() {

    double start;
    double end;
    double step;

    printf("Please enter start: ");
    scanf("%lf", &start);
    printf("Please enter end: ");
    scanf("%lf", &end);
    printf("Please enter step size: ");
    scanf("%lf", &step);
    while (start != end) {
        printf("%Lf\n", start);
        start += step;

    }
    return 0;
}
