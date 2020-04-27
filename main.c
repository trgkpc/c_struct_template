#include <stdio.h>
#include <stdlib.h>

#define def_vec(name, T, ADD, PRINTF, DELIMITER) \
    typedef struct {                             \
        T x;                                     \
        T y;                                     \
    } name;                                      \
                                                 \
    name sum_##name(name a, name b)              \
    {                                            \
        name c;                                  \
        c.x = ADD(a.x, b.x);                     \
        c.y = ADD(a.y, b.y);                     \
        return c;                                \
    }                                            \
                                                 \
    void print_##name(name a)                    \
    {                                            \
        PRINTF(a.x);                             \
        printf(DELIMITER);                       \
        PRINTF(a.y);                             \
    }

#define OPERATOR_PLUS(x, y) ((x) + (y))
#define PRINT_DOUBLE(x) printf("%lf", x)
#define PRINT_INT(x) printf("%d", x)

def_vec(Vectord, double, OPERATOR_PLUS, PRINT_DOUBLE, " ");
def_vec(Vector, int, OPERATOR_PLUS, PRINT_INT, " ");
def_vec(Mat, Vector, sum_Vector, print_Vector, "\n");

int main()
{
    // doubleのvector
    Vectord a = {2.0, 1.0};
    Vectord b = {4.0, -5.0};
    Vectord c = sum_Vectord(a, b);
    printf("c = \n");
    print_Vectord(c);
    printf("\n\n");

    // intのvector
    Vector v1 = {1, 2};
    Vector v2 = {5, 7};
    Vector v3 = sum_Vector(v1, v2);
    printf("v3 = \n");
    print_Vector(v3);
    printf("\n\n");

    // vector<int>のvector
    Mat M1 = {v1, v2};
    Mat M2 = {v2, v1};
    Mat M3 = sum_Mat(M1, M2);
    printf("M3 = \n");
    print_Mat(M3);
    printf("\n\n");
}
