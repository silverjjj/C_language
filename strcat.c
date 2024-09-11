/*
    char *strcat(char *dest, const char *src);
    // parameter
    dest    : 두 번째 문자열(src)이 이어 붙여질 첫 번째 문자열의 주소
    src     : 이어 붙일 두 번째 문자열
    
    // return value
    dest 포인터 반환

    // 동작방식
    1. dest의 끝을 찾기,, : 먼저 dest의 마지막(\0, null) 문자를 찾습니다.
    2. src를 dest에 복사
*/

#include <stdio.h>
#include <string.h>

#define TOTAL_MSSG_SIZE 4000

int main() {
    char buffer[TOTAL_MSSG_SIZE+1];             // 4000자의 문자열을 저장할 공간 (+1은 null terminator)
    char *message;          
    message = "Hello, World!";                  
    int message_len = strlen(message);          // "Hello, World!"의 길이 (13자)
    int total_length = 0;

    // 빈 문자열로 초기화
    buffer[0] = '\0';

    while (total_length + message_len <= TOTAL_MSSG_SIZE)
    {
        // message를 buffer함수에 추가
        strcat(buffer, message);
        total_length += message_len;
    }

    // 결과 출력
    printf("%s\n", buffer);
    printf("Total length: %d\n", total_length);

    return 0;
}
