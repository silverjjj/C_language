#include <iostream>
#include <string.h>

class Marine {
    private:
        int hp;                // 마린 체력
        int coord_x, coord_y;  // 마린 위치
        int damage;            // 공격력
        bool is_dead;
        char* name;         // 마린 이름

    public:
        Marine();              // 기본 생성자
        Marine(int x, int y);  // x, y 좌표에 마린 생성
        Marine(int x, int y, const char* marine_name);  // x, y 좌표에 마린 생성
        ~Marine();          // 소멸자(destructor)

        int attack();                       // 데미지를 리턴한다.
        void be_attacked(int damage_earn);  // 입는 데미지
        void move(int x, int y);            // 새로운 위치
        void show_status();  // 상태를 보여준다.
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 !" << std::endl;
    if (name != NULL)       // 동적으로 할당됐을경우,
        delete[] name;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine : " << name << " *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    // Marine marine1(2, 3);
    // Marine marine2(3, 5);

    // marine1.show_status();
    // marine2.show_status();

    // std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    // marine2.be_attacked(marine1.attack());

    // marine1.show_status();
    // marine2.show_status();


    Marine* marines[100];

    // new는 객체를 동적으로 생성하면서 동시에 자동으로 생성자도 호출해줌
    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(3, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    // delete를 지정하지 않으면 자동으로 delete 되지 않는다.
    // 다시 말해서 delete를 통해삭제하지 않는다면 우리가 동적으로 할당한 name의 경우 영원히 메모리속에서 존재할것이다. => memory leak
    // 이를 위해 소멸자가 등장함 (소멸자 : 객체가생성될때 자동으로 호출한 생성자처럼, 소멸될때 자동으로 호출하여 소멸됨)
    delete marines[0];
    delete marines[1];
}