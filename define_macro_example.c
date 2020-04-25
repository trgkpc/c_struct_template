#include <stdio.h>

#define A 200
#define f(x, y) ((x) + (y))
#define g(number)                            \
    do {                                     \
        printf("number <- not replaced.\n"); \
        printf("number is %d\n", number);    \
    } while (0)

int main()
{
    printf("number: %d\n", A);
    printf("x*y: %d\n", f(3, 19));
    int t = 40;
    g(t);

    printf("以下追記\n");
    for (int t = 0; t < 5; t++)
        g(t);
}
