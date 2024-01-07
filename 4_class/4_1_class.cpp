#include <iostream>


class Animal {

    private:            // private는 자기 객체 안에서만 접근할 수 있을뿐, 객체 외부에서는 접근할수 없다.
        int food;       // member variable
        int weight;

    public:
        void set_animal(int _food, int _weight)     // member function
        {   
            food = _food;
            weight = _weight;
        }

        void increase_food(int inc)
        {
            food += inc;
            weight += (inc / 3);
        }

        void view_stat() 
        {
            std::cout << "이 동물의 food : " << food << std::endl;
            std::cout << "이 동물의 weight : " << weight << std::endl;
        }      
};


int main() {

    Animal animal;          // instance 생성

    animal.set_animal(100, 50);
    animal.increase_food(30);    
    animal.view_stat();
    return 0;
}