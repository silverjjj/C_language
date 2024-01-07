#include <iostream>

int main()
{
    int lucky_number = 3;
    std::cout << "내 비밀의 수를 맞춰봐라" << std::endl;
    
    int user_input;

    while (1)
    {
        std::cout << "입력 : ";
        std::cin >> user_input;

        if (user_input == lucky_number)
        {
            std::cout << "정답입니다 !" << std::endl;    
            break;
        } 
        else
        {
            std::cout << "다시 맞춰보세요 " << std::endl;
        }
    }


    

    return 0;
}