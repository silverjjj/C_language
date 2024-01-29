/* 메모리의 배치 모습 */

#include <stdio.h>
int global = 3;
int main() {
  int i;
  char *str = "Hello, Baby";  
  char arr[20] = "WHATTHEHECK";

  printf("global : %p \n", &global);
  printf("i : %p \n", &i);
  printf("str : %p \n", str);
  printf("arr : %p \n", arr);
}

/*
global : 0000000000403010       // global variable
i : 000000000061FE14            // stack
str : 0000000000404000          // read only
arr : 000000000061FE00          // 

*/