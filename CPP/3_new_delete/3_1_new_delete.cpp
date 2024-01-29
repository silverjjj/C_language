/* new 와 delete 의 사용 
    c++에서도 malloc와 free 함수를 사용하여 메모리 할당을 할수 있지만,,
    c++ 차원에서 동적할당을 위해 지원하는것이 new와 delete이다.
*/

#include <iostream>

int main() {
    /*
        기본 사용 예시
        int 크기의 공간을 new로 할당하여 그 주소값을 p에 넣음
        형태 : type* pointer = new type
    */
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;

    /* new로 배열 할당하기*/
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;

    int *list = new int[arr_size];

    for (int i=0; i < arr_size; i++)
    {
        std::cin >> list[i];
    }

    for (int i=0; i < arr_size; i++)
    {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    } 

    // new []를 이용하여 할당했으면,, delete[]로 해제를 해야함..
    delete[] list;

    return 0;
}