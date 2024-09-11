#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;
	short	s = 1;	// 2 bytes = 2 * 8 bits = 16 bits / 2^16���� �� ǥ�� ����
	int	i = 1;
	long	l = 1;
	long long ll = 1;

	cout << sizeof(short) << endl;		// 2
	cout << sizeof(int) << endl;		// 4
	cout << sizeof(long) << endl;		// 4
	cout << sizeof(long long) << endl;	// 8

	cout << std::pow(2, sizeof(short) * 8) << endl;			// unsigned - 65535, -1�� ��ȣ��
	cout << std::pow(2, sizeof(short) * 8 - 1) - 1 << endl;	// signed - 32767, ��ȣ�� 0 ����
	cout << std::numeric_limits<short>::max() << endl;		// 32767
	cout << std::numeric_limits<short>::min() << endl;		// -32768
	cout << std::numeric_limits<short>::lowest() << endl;	// -32768

	s = 32767;
	s += 1;	// 32768 (++s, s++)

	cout << "32768? " << s << endl;		// overflow : short�� �ִ� ũ���� 32767���� ū ���ڰ� ���� overflow �߻�

	short s2 = std::numeric_limits<short>::min();
	cout << "min() " << s2 << endl;		// overflow
	s2 -= 1;

	cout << "-32768 ?? " << s2 << endl;		


	// ����! unsigned int�� signed int�� ������ unsigned�� �ٲ� �ش�.
	// -1�� signed int�ε�, unsigned int�� Ÿ���� ���ϸ� ���ڰ� �̻��ϰ� ����
	unsigned int i2 = -1;
	cout << i2 << endl;

	// ����! ���������� ������ ������ �����Ѵ�.
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