/*
    소멸자 호출 확인하기
*/
#include <string.h>
#include <iostream>

class Test {
    private:
        char c;
    
    public:
        Test(char _c);
        ~Test();
};

Test::Test(char _c) 
{
    c = _c;
    std::cout << "생성자 호출 " << c << std::endl;
}

Test::~Test()
{
    std::cout << "소멸자 호출 " << c << std::endl;
}

void simple_function() 
{ 
    Test b('b'); 
}


int main() {
  Test a('a');
  simple_function();
}

/*
    생성자 호출 a
    생성자 호출 b
    소멸자 호출 b
    소멸자 호출 a
*/