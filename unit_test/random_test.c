#include <stdio.h>
#include "random.h"

int main() {
    int n = ~0;
    printf("~0 = %d\n", n);

    n = (unsigned)~0 >> 1;
    printf("~0 >> 1 = %d\n", n);

    Randomize();

    int ri = RandomInteger(1, 100);
    printf("random integer is %d\n", ri);

    double rd = RandomReal(5.5, 6.9);
    printf("random real is %lf\n", rd);

    bool chance = RandomChance(0.3);
    printf("random chance %d\n", chance);
}