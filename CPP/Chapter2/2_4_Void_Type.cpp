void my_funtion(void)
{

}

int main()
{
	//void my_void;	error! void는 메모리를 차지하지 않는다.
	int i = 123;
	float f = 123.456f;

	void *my_void;	// 주소, 포인터
	
	// 데이터 타입이 다르더라도, "주소"의 데이터 타입 동일하다.
	my_void = (void*)&i;	// 정수형 변수의 주소
	my_void = (void*)&f;	// 실수형 변수의 주소
	
	// 위 i,f 변수의 주소의 데이터 타입은 동일함

	return 0;
}