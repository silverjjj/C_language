/* dynamic memory allocation */
#include <iostream>
#include <stdlib.h>
/*
    동적 메모리 할당이란?
    말 그대로 입력을 받는 대로 메모리에 크기를 할당하는것
*/

int main(int argc, char **argv)
{
    int SizeOfArray;
    int *arr;

    printf (" 만들고 싶은 배열의 원소 수 : " );
    scanf("%d", &SizeOfArray);
    
    // int arr[SizeOfArray] 와 동일한 크기의 배열을 생성
    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    /*  
        malloc : heap 영역에 메모리를 할당
        (int *) : malloc의 return이 void* 이므로 (int*)로 형변환 하는것
        sizeof(int) : sizeof()는 괄호안에 자료형 타입을 기준으로 연산해주기 위함
        sizeof(int) * SizeOfArray : 메모리를 int type * SizeOfArray 크기로 할당

        sizeof(int) * SizeOfArray 크기를 int 형으로 형변환 하여 arr에 넣어준다.
    */

    // free : arr를 다쓰고나서 해제하는 함수 
    // free를 통해 memory leak를 방지
    free(arr);  



    return 0;
}