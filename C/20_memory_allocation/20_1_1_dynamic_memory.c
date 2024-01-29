/* 동적 할당의 활용 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int student;
    int i, input;
    int *score;
    int sum = 0;

    printf("학생의 수는 ? : ");
    scanf("%d", &student);

    /*
        malloc : memory allocation의 약자
        void* malloc(size_t size)
        1. (sizeof(int) * student) byte만큼 heap 영역에 메모리 할당
        2. void* -> int*로 캐스팅 (형변환)
        3. 해당 메모리 공간을 int *score에 대입

        free : 메모리의 해제
        void free(void *ptr);
        ptr : 해제하고자 하는 메모리의 포인터
    */
    score = (int *)malloc(sizeof(int) * student);
    
    for (i = 0; i < student; i++)
    {
        printf("학생 %d의 점수 : ", i );
        scanf("%d", &input);
        score[i] = input;
        sum += input;
    }
    
    printf("전체 학생 평균 점수 : %d \n", sum / student);

    free(score);
    return 0;
}