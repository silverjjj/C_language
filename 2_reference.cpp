// 2. C++ 참조자(reference)의 도입
#include <iostream>

int change_val(int *p)
{
    *p = 3;
    return 0;
}

void change_val2(int &p)     // reference로 함수 인자 받기
{
    p = 3;
}

int function()
{
    int a4 = 2;
    return a4;
}

int& function2() {
  int a5 = 2;
  return a5;
}

int main()
{   
    // ****** 참조자 도입 ******
    /*
        c에선 change_val 함수 인자 p에 number의 주소값을 전달하여,
        *p를 통해 number을 참조하여 number의 값을 3으로 바꿈
    */
    int number = 5;
    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;

    /*
        c++에서는 다른 변수나 상수를 가리키는 방법으로 다른 방식을 제공함 
        이것이 바로 reference (참조자)
    */
    int a = 3;
    int& another_a = a;             // a의 reference another_a를 정의함
                                    // reference를 정하는 방법은, 가리키고자 하는 type뒤에 &을 붙인다.
    another_a = 5;
    std::cout << "a : " << a << std::endl;                  // 5
    std::cout << "another_a : " << another_a << std::endl;  // 5

    // reference가 한 번 별명이 되면 절대 다른 이의 별명이 될 수 없다.
    int b = 3;
    // int& another_a = b;      // error 발생



    // ****** 함수 인자로 레퍼런스 받기 ******
    int number2 = 5;
    int gg;
    /*
        change_val2(number2)이 호출될때, 사실상
        "int& p = number" 가 실행되는거다
        위 실행과 함께
        "p야 너는 앞으로 number의 새로운 별명이야!" 라고 말해주는것과 다름없다.
    */
    std::cout << number2 << std::endl;      // 5
    change_val2(number2);
    std::cout << number2 << std::endl;      // 3
    


    // ****** 여러가지 참조자 예시들 ******
    /*
        y는 x의 reference
        z는 x의 reference
    */
    int x;
    int& y = x;
    int& z = y;

    x = 1;
    std::cout << "x :" << x << ", y : " << y << ", z : " << z << std::endl;     // x :1, y : 1, z : 1

    y = 2;
    std::cout << "x :" << x << ", y : " << y << ", z : " << z << std::endl;     // x :2, y : 2, z : 2
    
    z = 3;
    std::cout << "x :" << x << ", y : " << y << ", z : " << z << std::endl;     // x :3, y : 3, z : 3
    


    // ****** 상수에 대한 참조자 ******
    /*
        literal (리터럴)이란 ? 소스코드 상에서 고정된 값을 가지는 것을 일컫습니다.
        특히 C언어에서는 ""로 묶인 것들을 리터럴이라고 부른다.
    */
    // 상수인 4는 리터럴이라서 이처럼 reference 로 참조할 수 없음.
    // int &ref = 4;

    // 단 상수 참조자로 는 사용 가능함
    const int &ref = 4;
    int aa = ref;       
    std::cout << "aa : " << aa << std::endl;        // aa : 4


    // ****** 레퍼런스의 배열과 배열의 레퍼런스 ******
    /*
        reference의 배열은 불가능함
        배열은 arr의 주소가 arr[0]의 주소로 변환이 될수 있어야함 ( 주소가 존재한다는것은 해당 원소가 메모리 상에 존재한다 라는 의미)
        reference는 특별한 경우가 아닌이상 메모리 상에 공간을 차지 하지 않는다.
        이런 모순 때문에 reference들의 배열을 정의하는것은 금지됨
    */
    int a3;
    int b3;
    // int& arr[2] = {a3,b3};

    
    /*
        배열들의 reference는 가능함
    */
    int arr[3] = {1, 2, 3};
    int(&ref2)[3] = arr;        // ref가 arr를 참조함

    ref2[0] = 2;
    ref2[1] = 3;
    ref2[2] = 1;
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;

    // 2차원 배열도 참조 가능함
    int arr2[3][2] = {1,2,3,4,5,6};
    int(&ref3)[3][2] = arr2;


    // ****** 레퍼런스를 리턴하는 함수 ******
    /*
        function 함수를 보면 
        function이 종료되면 그와 동시에 a4는 사라짐,
        이를 참고하여 아래 예시를 보자
    */
    int b4 = function();
    std::cout << " b4 : " << b4 << std::endl;

    // 이 부분 이해 안감,
    int b5 = function2();

    

    return 0;
}