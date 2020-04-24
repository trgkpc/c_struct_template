#include <iostream>

// Vector型の定義
template <class T>
struct Vector {
    T x;
    T y;
    // 加法の定義
    Vector<T> operator+(const Vector<T>& v) const
    {
        return {x + v.x, y + v.y};
    }
};

// Vectorをostreamに出力できるようにする
template <class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v)
{
    os << v.x << " " << v.y;
    return os;
}

template <class T>  // templateの特殊化
std::ostream& operator<<(std::ostream& os, const Vector<Vector<T>>& v)
{
    os << v.x << std::endl;
    os << v.y;
    return os;
}

int main()
{
    // 各要素がdouble型のVectorの例
    Vector<double> a{2.0, 1.0};
    Vector<double> b{4.0, -5.0};
    Vector<double> c = a + b;
    std::cout << "c = " << std::endl;
    std::cout << c << std::endl
              << std::endl;

    // 各要素がint型のVectorの例
    Vector<int> x{1, 2};
    Vector<int> y{5, 7};
    Vector<int> z = x + y;
    std::cout << "z = " << std::endl;
    std::cout << z << std::endl
              << std::endl;

    // 各要素がVector<int> 型のVectorの例
    Vector<Vector<int>> A{x, y};
    Vector<Vector<int>> B{y, x};
    Vector<Vector<int>> C = A + B;
    std::cout << "C = " << std::endl;
    std::cout << C << std::endl;
}
