/*
    char *strcpy(char *dest, const char *src);
    매개변수:
    dest: 복사할 문자열이 저장될 목적지 배열(메모리).
    src: 복사할 원본 문자열.
    
                복사 대상               데이터 유형                             null문자처리        일반적인사용용도
    memcpy  :   메모리 전체를 복사      문자열,구조체,배열 등 모든데이터 저장   null문자 처리 안함  메모리 블록,구조체,배열복사
    strcpy  :   문자열을 복사           문자열 복사 전용                        \0문자까지 복사     문자열복사
    
*/

#include <stdio.h>
#include <string.h>

#define TOTAL_MSSG_SIZE 4000

int main() {
    char buffer[TOTAL_MSSG_SIZE+1];  // 4000자의 문자열을 저장할 공간 (+1은 null terminator를 위해)
    char *message = "Hello, World!";  // 반복할 문자열
    int message_len = strlen(message);  // 문자열 길이 (13자)
    int total_length = 0;


    char *current_pos = buffer;

    // 4000자를 넘지 않도록 반복하여 message를 복사
    while (total_length + message_len <= TOTAL_MSSG_SIZE) {

        // 1. current_pos 위치에 message을 복사하고
        strcpy(current_pos, message);
        total_length += message_len; 
        
        // 2. 다음 포인터로 이동시킴
        current_pos += message_len;
    }

     // 버퍼의 나머지를 'H' 문자로 채워서 정확히 4000자가 되도록 함
    while (total_length < 4000) {
        *current_pos = 'H';
        current_pos++;
        total_length++;
    }

    buffer[total_length] = '\0';  // 마지막에 null 문자 추가하여 문자열 종료

    // 결과 출력
    printf("Buffer: %s\n", buffer);
    printf("Total length: %d\n", total_length);

    return 0;
}

