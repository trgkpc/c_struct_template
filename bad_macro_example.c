#include <stdio.h>

#define f(x, y) x + y
#define g(number)                        \
    printf("number <- not replaced.\n"); \
    printf("number is %d\n", number)

int main()
{
    printf("x*y: %d\n", f(12 >> 2, 38 >> 1));
    int i = 0;
    for (i = 0; i < 5; i++)
        g(i);
}
