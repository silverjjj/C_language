/*
    char vs string
    char
        - 크기가 정해져있고, 정적할당
        - 내장 함수가 없고, strcpy, strcat, strlen 등의 함수를 사용해야함
    
    string
        - 크기 조절, 동적할당
        - 내장 함수가 제공, 메모리 할당과 해제, 함수 호출등 오버헤드가 발생할 수 있음
*/

// #include <string.h>
#include <iostream>

class string {
    private:
        char *str;
        int len;

 public:
    string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);   // str 뒤에 s 를 붙인다.
    void copy_string(const string &s);  // str 에 s 를 복사한다.
    int strlen();                       // 문자열 길이 리턴
    void string_status();
};


string::string(char c, int n)
{
    len = n;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = c;
    }
    str[n] = '\0';

    std::cout << "기본 생성자 1 : " << str << std::endl;
}

string::string(const char *s)
{
    
    len = 0;
    while (s[len] !='\0')
        len ++;

    // 기본 생성자에서 동적할당된 name의 경우, 복사 생성자에서도 다시 동적할당해야한다.
    str = new char[len+1];

    for (int i=0; i < len; i++)
        str[i] = s[i];
    
    str[len]='\0';
    std::cout << "기본 생성자 2 : " << str << std::endl;
}

string::string(const string &s)
{
    len = s.len;
    str = new char[len+1];
    for (int i=0; i < len; i++)
        str[i] = s.str[i];
    
    str[len] = '\0';
    std::cout << "복사 생성자 : " << str << std::endl;
}

string::~string()
{
    if (str) delete[] str;
    std::cout << "소멸 생성자" << std::endl;
}

void string::add_string(const string &s)
{
    char* tmp = new char[len + s.len + 1];
    for (int i = 0; i < (len + s.len + 1); i++) 
    {
		if (i < (len)) {
			tmp[i] = str[i];
		}
		else if (i >= len) {
			tmp[i] = s.str[i-len];
		}
	}

    for (int i = 0; i < len + s.len; i++) {
		str[i] = tmp[i];
	}
    str[len + s.len] = '\0';
	delete[] tmp;
	std::cout << "기존 문자열에 추가한 결과 : "<< str<< std::endl;
}

void string::copy_string(const string &s)
{
    delete str;
    str = new char[s.len+1];
    str = s.str;
    len = s.len;
    std::cout << "문장 복사 : "<< str << std::endl;
}

void string::string_status()
{
    std::cout << "현재 문자열 : " << str << std::endl;
}

int string::strlen() 
{
    return len;
}

int main()
{
    string a('a', 10);      // 기본 생성자
    string b("ssss");       // 기본 생성자
	string c(a);            // 복사 생성자
    c.add_string(b);        
    c.copy_string(b);
    c.string_status();
    std::cout << "현재 문자열 크기 : " << c.strlen() << std::endl;
}