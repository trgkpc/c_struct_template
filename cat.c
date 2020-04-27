#include <stdio.h>

#define new_int(num, value) int v##num = (value)

int main()
{
    new_int(0, 0);
    new_int(1, 10);
    new_int(a, -50);

    printf("%d\n", v0);
    printf("%d\n", v1);
    printf("%d\n", va);
}
