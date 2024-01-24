#include <iostream>
/*
    std은 c++ 표준 라이브러리의 모든 함수 객체 등이 정의된곳
    namespace란 어떤 정의된 객체에 대해 어디 소속인지 지정해주는것과 동일함
*/

namespace A {
    void printAll() {
        std::cout << "A의?printAll?함수" << std::endl;
    }
}

namespace B {
    void printAll() {
        std::cout << "B의 printAll?함수" << std::endl;
    }
}


int main(void)
{
    A::printAll();
    B::printAll();
    return 0;
}
