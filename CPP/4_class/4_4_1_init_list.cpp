/*
    생성자의 초기화 리스트(initalizer list)

*/
#include <iostream>

class Marine {
    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    // int damage;            // 공격력
    const int default_damage;  // 기본 공격력
    bool is_dead;

    public:
        Marine();              // 기본 생성자
        Marine(int x, int y);  // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);    // default_damage 인자 추가

        int attack();                       // 데미지를 리턴한다.
        void be_attacked(int damage_earn);  // 입는 데미지
        void move(int x, int y);            // 새로운 위치

        void show_status();  // 상태를 보여준다.
};

/*
    초기화 리스트 예시
    (생성자 이름) : var1(arg1), var2(arg2) {}
    초기화 리스트는 생성과 초기화를 동시에 한다.
    
    초기화 리스트를 사용하지 않는다면, 생성을 먼저하고 그 다음에 대입을 수행하는것
*/
// 초기화 리스트 사용 방법들
// Marine 이름을 가진 메소드가 3개라, 인자에 따라 오버로딩이 된다.
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage) 
    : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {}

void Marine::move(int x, int y) 
{
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) 
{
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3, 10);       // marine1은 Marine(int x, int y, int default_damage) 을 통해 initializer list
    Marine marine2(3, 5);           // marine2는 Marine(int x, int y) 을 통해 initializer list

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    std::cout << std::endl << "마린 2 가 마린 1 을 공격! " << std::endl;
    marine1.be_attacked(marine2.attack());

    marine1.show_status();
    marine2.show_status();
}