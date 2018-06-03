#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Box2 {
    T1 firstData;
    T2 secondData;

public:
    Box2() {}
    T1 getFirst();
    T2 getSecond();
    void setFirst(T1 value) {
        firstData = value;
    }

    void setSecond(T2 value) {
        secondData = value;
    }
};

template <typename T1, typename T2>
T1 Box2<T1, T2>::getFirst() {
    return firstData;
}

template <typename T1, typename T2>
T1 Box2<T1, T2>::getSecond() {
    return SecondData;
}


int main()
{

    Box2<int, double> b;
    b.setFirst(10);
    b.setSecond(3.14);
    cout << "(" << b.

    return 0;
}
