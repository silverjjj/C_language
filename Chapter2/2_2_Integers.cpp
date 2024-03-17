#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;
	short	s = 1;	// 2 bytes = 2 * 8 bits = 16 bits / 2^16가지 수 표현 가능
	int	i = 1;
	long	l = 1;
	long long ll = 1;

	cout << sizeof(short) << endl;		// 2
	cout << sizeof(int) << endl;		// 4
	cout << sizeof(long) << endl;		// 4
	cout << sizeof(long long) << endl;	// 8

	cout << std::pow(2, sizeof(short) * 8) << endl;			// unsigned - 65535, -1은 부호용
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;	// signed - 32767, 부호와 0 제외
	cout << std::numeric_limits<short>::max() << endl;		// 32767
	cout << std::numeric_limits<short>::min() << endl;		// -32768
	cout << std::numeric_limits<short>::lowest() << endl;	// -32768

	s = 32767;
	s += 1;	// 32768 (++s, s++)

	cout << "32768? " << s << endl;		// overflow : short의 최대 크기인 32767보다 큰 숫자가 나와 overflow 발생

	short s2 = std::numeric_limits<short>::min();
	cout << "min() " << s2 << endl;		// overflow
	s2 -= 1;

	cout << "-32768 ?? " << s2 << endl;		


	// 주의! unsigned int에 signed int를 넣으면 unsigned로 바꿔 준다.
	// -1은 signed int인데, unsigned int로 타입을 정하면 숫자가 이상하게 나옴
	unsigned int i2 = -1;
	cout << i2 << endl;

	// 주의! 정수끼리의 연산은 정수로 저장한다.
	cout << 22 / 4 << endl;
	cout << (float)22 / 4 << endl;


	cout << "int size: " << sizeof(int) << endl;
	cout << "u-int size: " << sizeof(unsigned int) << endl;

	cout << "\nint max: " << std::numeric_limits<int>::max() << endl;
	cout << "u-int max: " << std::numeric_limits<unsigned int>::max() << endl;

	cout << "\nint min: " << std::numeric_limits<int>::min() << endl;
	cout << "u-int min: " << std::numeric_limits<unsigned int>::min() << endl;

	cout << "\nint lowest: " << std::numeric_limits<int>::lowest() << endl;
	cout << "u-int lowest: " << std::numeric_limits<unsigned int>::lowest() << endl;


	return 0;
}