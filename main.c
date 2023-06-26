#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
    if (k == 0) {
        *f2k = 0;
        *f2k1 = 1;
    } else if (k == 1) {
        *f2k = 1;
        *f2k1 = 2;
    } else {
        if (k % 2) {
            fib_fast_doubling(k / 2, f2k, f2k1);
            unsigned long long f = *f2k, f1 = *f2k1;
            *f2k = f * (2 * f1 - f);
            *f2k1 = f * f + f1 * f1;
            *f2k += *f2k1;
            *f2k1 += *f2k;
        } else {
            fib_fast_doubling(k / 2, f2k, f2k1);
            unsigned long long f = *f2k, f1 = *f2k1;
            *f2k = f * (2 * f1 - f);
            *f2k1 = f * f + f1 * f1;
        }
    }
}
int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}