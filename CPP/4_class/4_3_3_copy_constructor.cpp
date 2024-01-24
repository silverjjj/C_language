/*
    복사 생성자
    : 한개의 생성자를 만들고, 그 한개를 가지고 복사 생성을 하는것

    예시) 
    Photon_Cannon(const Photon_Cannon& pc)          << 복사 생성자 사용 방법
    Photon_Cannon 클래스가 있다면,
    다른 Photon_Cannon의 객체 pc를 상수 래퍼런스로 받는다.
    const이기 때문에 복사 생성자 내부에서 pc의 데이터를 변경할 수 없고, 인스턴스 변수들만 복사하는것,,,
    다시 말해서 이미 생성되어진 생성자 pc의 값을 변경하지 못하고 그대로 가져온거임,, 
*/

#include <string.h>
#include <iostream>
class Photon_Cannon
{
    private:
        int hp, shield;
        int coord_x, coord_y;
        int damage;
        char *name;

    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char *cannon_name);

        // 복사를 해주는 부분이 없어도 디폴트 복사 생성자가 존재함,, 하지만 한계가 있음
        Photon_Cannon(const Photon_Cannon& pc);     // const : 고정되어 있어야할 변수 값을 지정할 때 사용함

        ~Photon_Cannon();
        
        void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) 
{
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) 
{
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];       // name 동적할당
    strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon()
{
    std::cout << "소멸자 호출 !" << std::endl;
    if (name) delete[] name;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc)       // pc는 포인터
{
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;                     // 얕은복사
    shield = pc.shield;             // 얕은복사
    coord_x = pc.coord_x;           // 얕은복사
    coord_y = pc.coord_y;           // 얕은복사
    damage = pc.damage;             // 얕은복사
    
    // name = pc.name;                 // 얕은복사 : 에러 발생시킴
    name = new char[strlen(pc.name) + 1];    // name의 경우 따로 메모리를 할당해서 그 내용만 복사를 하는 깊은 복사를 수행
    strcpy(name, pc.name);
}

void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main()
{
    // 1. 복사 생성자에 대해
    // Photon_Cannon pc1(3, 3);
    // Photon_Cannon pc2(pc1);         // 복사 생성자 pc2
    // Photon_Cannon pc3 = pc2;        // 복사 생성자 pc3
    
    // pc1.show_status();
    // pc2.show_status();

    // 2. Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 에서 name 동적할당해서 그 내용만 다시 깊은 복사해준다
    //      동적할당 해주지 않으면, 기본 생성자가 소멸됨과 동시에 name에 할당된 메모리까지 delete하게 된다.
    //      그래서 복사 생성자의 name에도 새로 동적 할당 해주어, 기본 생성자가 소멸되도 영향이 없게 한다 ==> 깊은복사
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
}