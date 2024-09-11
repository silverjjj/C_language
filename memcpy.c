/*
    void *memcpy(void *dest, const void *src, size_t n);
    dest    : 데이터를 복사할 대상 메모리의 시작 주소.
    src     : 복사할 원본 데이터의 시작 주소.
    n       : 복사할 바이트 수.
*/

#include <stdio.h>
#include <string.h>

#define TOTAL_MSSG_SIZE 4000

int main() {
    char buffer[TOTAL_MSSG_SIZE+1];             // 4000자의 문자열을 저장할 공간 (+1은 null terminator)
    char *message;          
    message = "Hello, World!";                  // 문자열을 포인터로 받음
    int message_len = strlen(message);          // "Hello, World!"의 길이 (13자)
    int total_length = 0;

    // 버퍼를 반복해서 채울 위치를 가리키는 포인터 
    // buffer 배열에 첫 주소가 current_pos에 있음
    char *current_pos = buffer;
    printf("Address of current_pos : %p \n", &message);
    printf("Address of buffer : %p \n", &buffer[0]);

    while (total_length + message_len <= TOTAL_MSSG_SIZE) {
        // 1. current_pos 주소에 message를 복사
        memcpy(current_pos, message, message_len);
        total_length += message_len;              

        // 2. 다음 포인터로 이동시킴
        current_pos += message_len;               
    }

    buffer[total_length] = '\0';  // 마지막에 null 문자 추가하여 문자열 종료

    // 결과 출력
    printf("%s\n", buffer);
    printf("Total length: %d\n", total_length);

    return 0;
}