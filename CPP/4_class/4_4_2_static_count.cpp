// static 함수
/*
    static을 사용한 멤버변수의 경우,,,
    클래스의 모든 객체들이 '공유'하는 변수로써 각 객체별 따로 존재하는 멤버변수와 달리
    모든 객체들이 하나의 static 멤버변수를 사용함
    
    hp, coord_x, coord_y, is_dead, default_damage는 각 객체가 따로 변수를 갖지만
    total_marine_num와 i는 모든 객체가 공유하는 static 변수이다.
    
*/
#include <iostream>

class Marine {
    static int total_marine_num;        // 총 마린 명수
    const static int i = 0;
    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    bool is_dead;
    const int default_damage;  // 기본 공격력

    public:
        Marine();              // 기본 생성자
        Marine(int x, int y);  // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);

        int attack();                       // 데미지를 리턴한다.
        void be_attacked(int damage_earn);  // 입는 데미지
        void move(int x, int y);            // 새로운 위치

        void show_status();  // 상태를 보여준다.
        static void show_total_marine();
        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
        coord_y(y),
        hp(50),
        default_damage(default_damage),
        is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}

int main() {
    Marine marine1(2, 3, 5);
    Marine::show_total_marine();

    Marine marine2(3, 5, 10);
    Marine::show_total_marine();

    /*
        지역변수 create_marine에서 Marine에 대한 객체를 생성함
        지역변수가 종료되면 자동으로 해당 객체는 사라짐
    */
    create_marine();        

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}