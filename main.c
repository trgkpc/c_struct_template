#include <stdio.h>
#include <stdlib.h>

#define def_vec(name, T, ADD, PRINTF, DELIMITER, \
    sum, print)                                  \
    typedef struct {                             \
        T x;                                     \
        T y;                                     \
    } name;                                      \
                                                 \
    name sum(name a, name b)                     \
    {                                            \
        name c;                                  \
        c.x = ADD(a.x, b.x);                     \
        c.y = ADD(a.y, b.y);                     \
        return c;                                \
    }                                            \
                                                 \
    void print(name a)                           \
    {                                            \
        PRINTF(a.x);                             \
        printf(DELIMITER);                       \
        PRINTF(a.y);                             \
    }

#define OPERATOR_PLUS(x, y) x + y
#define PRINT_DOUBLE(x) printf("%lf", x)
#define PRINT_INT(x) printf("%d", x)

def_vec(Vectord, double, OPERATOR_PLUS, PRINT_DOUBLE, " ", sum_vectord, print_vectord);
def_vec(Vector, int, OPERATOR_PLUS, PRINT_INT, " ", sum_vector, print_vector);
def_vec(Mat, Vector, sum_vector, print_vector, "\n", sum_mat, print_mat);

int main()
{
    // doubleのvector
    Vectord a;
    a.x = 2.0;
    a.y = 1.0;
    Vectord b;
    b.x = 4.0;
    b.y = -5.0;
    Vectord c = sum_vectord(a, b);
    printf("c = \n");
    print_vectord(c);
    printf("\n\n");

    // intのvector
    Vector v1;
    v1.x = 1;
    v1.y = 2;
    Vector v2;
    v2.x = 5;
    v2.y = 7;
    Vector v3 = sum_vector(v1, v2);
    printf("v3 = \n");
    print_vector(v3);
    printf("\n\n");

    // vector<int>のvector
    Mat M1;
    M1.x = v1;
    M1.y = v2;
    Mat M2;
    M2.x = v2;
    M2.y = v1;
    Mat M3 = sum_mat(M1, M2);
    printf("M3 = \n");
    print_mat(M3);
    printf("\n\n");
}
