#include <iostream>

class Date {
    private:
        int year_;
        int month_;
        int day_;

    public:
        void SetDate(int year, int month, int day);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        // 해당 월의 총 일 수를 구한다.
        int GetCurrentMonthTotalDays(int year, int month);

        void ShowDate();

    Date(int year, int month, int day)  // 생성자를 위한 메소드
    {
        year_ = year;
        month_ = month;
        day_ = day;
    }

    Date()                              // 디폴트 생성자
    {
        year_ = 1;
        month_ = 1;
        day_ = 1;
    }
};


// 대분의 함수는 클래스 밖에 정의된다.
// 왜냐하면 클래스 내부에 쓸 경우 클래스 크기가 너무 커져서 보기 좋지 않다.

void Date::SetDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date:: GetCurrentMonthTotalDays(int year, int month) {
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) {
    return month_day[month - 1];
  } else if (year % 4 == 0 && year % 100 != 0) {
    return 29;  // 윤년
  } else {
    return 28;
  }
}

void Date::AddDay(int inc) {
  while (true) {
    // 현재 달의 총 일 수
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // 같은 달 안에 들어온다면;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // 다음달로 넘어가야 한다.
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      AddMonth(1);
    }
  }
}

void Date::AddMonth(int inc) 
{
  AddYear((inc + month_ - 1) / 12);
  month_ = month_ + inc % 12;
  month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}


int main()
{   
    // 생성자 : Date 클래스의 day 객체를 만들면서 Date(int year, int month, int day) 를 호출한다는 의미
    Date day(2011, 3, 1);             // 생성자(Constructor) : 암시적방법 (implicit)
    Date day2 = Date(2016, 6, 12);    // 생성자(Constructor) : 명시적 방법 (explicit)
    Date day3 = Date();               // 디폴트 생성자
    Date day4;                        // 생성자 없이 객체 생성

    day.ShowDate();
    day2.ShowDate();
    day3.ShowDate();

    day4.SetDate(2011, 3, 1);
    day4.ShowDate();

    day4.AddDay(30);
    day4.ShowDate();

    day4.AddDay(2000);
    day4.ShowDate();

    // day.SetDate(2012, 1, 31);  // 윤년
    // day.AddDay(29);
    // day.ShowDate();

    // day.SetDate(2012, 8, 4);
    // day.AddDay(2500);
    // day.ShowDate();
    return 0;
}