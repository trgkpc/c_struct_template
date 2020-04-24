#include <stdio.h>

#define A 200
#define f(x, y) x + y
#define g(number)                        \
    printf("number <- not replaced.\n"); \
    printf("number is %d\n", number)

int main()
{
    printf("number: %d\n", A);
    printf("x*y: %d\n", f(3, 19));
    int t = 40;
    g(t);
}
