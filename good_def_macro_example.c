#include <stdio.h>

#define f(x, y) ((x) + (y))
#define g(number)                            \
    do {                                     \
        printf("number <- not replaced.\n"); \
        printf("number is %d\n", number);    \
    } while (0)

int main()
{
    printf("x+y: %d\n", f(12 >> 2, 38 >> 1));
    for (int t = 0; t < 5; t++)
        g(t);
}
