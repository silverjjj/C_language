// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
    int x;

 public:
    A(int c) : x(c) {}

    int& access_x() { return x; }
    int get_x() { return x; }
    void show_x() { std::cout << this->x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    int& c = a.access_x();  // c는 a의 참조자,, 동시에 같은 주소를 가리킨다.
                            // c는 a의 별명이라고 생각하면됨,, 쉽게 말해 같은놈인데 이름만 달라짐
    c = 4;
    a.show_x();

    int d = a.access_x();  // a의 값인 4가 d에 그냥 들어가는것,,
    d = 3;
    a.show_x();

    // 아래는 오류
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();

    int f = a.get_x();
    f = 1;
    a.show_x();
}