#include <iostream>

/*
    문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
    문자열 길이를 구하는 함수
    문자열 뒤에 다른 문자열 붙이기
    문자열 내에 포함되어 있는 문자열 구하기
    문자열이 같은지 비교
    문자열 크기 비교 (사전 순)
*/

class MyString {
    char* string_content;       // 문자열 데이터를 가리키는 포인터
    int string_lenght;

    public:
        // 오버로딩
        // 1. 문자 하나로 부터 생서
        MyString(char c);
        // 2. 문자열로부터 생성
        MyString(const char* str);
        // 3. 복사 생성자
        MyString(const MyString& str);

};

MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_lenght = 1;
}

MyString::MyString(const char* str)
{
    string_lenght = strlen(str);
    string_content = new char[string_lenght];
    for (int i=0; i<string_lenght; i++)
    {
        string_content[i]=str[i];
    }
}

int main()
{
    
    return 0;
}