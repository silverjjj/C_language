#include <iostream>

int main()
{
    /*
        char
        char은 1byte 변수이다. 즉 문자 하나를 뜻하는것이며, 
        나아가 2byte인 한글과는 문자 길이가 맞지않아 깨진다.
        그리고 char에 정수를 넣어도 ASCII 코드로 해석한다.
    */
    char singleChar  = 65;
    std::cout << "singleChar : " << singleChar << std::endl;

    char singleChar2 = 'b';
    std::cout << "singleChar2 : " << singleChar2 << std::endl;

    /*
        char*   : 포인터 변수로서 문자열의 주소값을 담는다
        char*은 문자열을 나타내는것
        문자의 포인터 변수를 문자열을 담기 위해 사용함
        char * str ="가나다라마바사" 일 때 포인터가 변수는 
        첫 글자 이자 문자열의 시작 주소(가나다라마바사에서 '가')를 가리킴
    */
    const char* cStyleString  = "abcd";
    std::cout << "cStyleString  : " << cStyleString  << std::endl;

    /*
        char[]
        char[]은 문자열을 나타내는데 사용되는 고정 크기 배열이다.
    */
    char fixedSizeArray[] = "Hello, c++!!";
    std::cout << "fixedSizeArray : " << fixedSizeArray << std::endl;

    /*
        char * vs char[]
        char*은 포인터로, 크기가 동적이며 문자열 끝에는 종료문자인 \n이 있음
        char[]은 배열로, 크기가 고정임
    */


    /*
        string
        string은 c++에서 동적으로 문자열을 작성할수있음
    */
   
   
    std::string myString = "Hello, C++";

    std::cout << myString << std::endl;
    
    std::cout << "length : " << myString.length() << std::endl;

    std::string addString = " Welcomm! ";
    myString += addString;
    std::cout << myString << std::endl;


    // 내가 헷갈리는 부분 : 문자열에 포인터 사용하는부분
    char cc = 'c';
    char* pointerToChar = &cc;

    std::cout << "cc: " << cc << std::endl; 
    std::cout << "Address of Char: " << &cc << std::endl;
    
    *pointerToChar = 'd';

    std::cout << "cc: " << cc << std::endl; 
    std::cout << "Address of Char: " << &cc << std::endl;
    
    
    return 0;
}