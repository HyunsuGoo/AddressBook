#define _CRT_SECURE_NO_WARNINGS
#include "AnniversaryDate.h"

uint32_t AnniversaryDate::getBirthYear() const
{
    return this->birthYear;
}
void AnniversaryDate::setBirthYear(uint32_t birthyear)
{
    this->birthYear = birthyear;
}
uint32_t AnniversaryDate::getBirthMonth() const
{
    return this->birthMonth;
}
void AnniversaryDate::setBirthMonth(uint32_t birthmonth)
{
    this->birthMonth = birthmonth;
}
uint32_t AnniversaryDate::getBirthDay() const
{
    return this->birthDay;
}
void AnniversaryDate::setBirthDay(uint32_t birthday)
{
    this->birthDay = birthday;
}
uint32_t AnniversaryDate::getAnniversaryYear() const
{
    return this->anniversaryYear;
}
void AnniversaryDate::setAnniversaryYear(uint32_t anniversaryyear)
{
    this->anniversaryYear = anniversaryyear;
}
uint32_t AnniversaryDate::getAnniversaryMonth() const
{
    return this->anniversaryMonth;
}
void AnniversaryDate::setAnniversaryMonth(uint32_t anniversarymonth)
{
    this->anniversaryMonth = anniversarymonth;
}
uint32_t AnniversaryDate::getAnniversaryDay() const
{
    return this->anniversaryDay;
}
void AnniversaryDate::setAnniversaryDay(uint32_t anniversaryday)
{
    this->anniversaryDay = anniversaryday;
}
std::string AnniversaryDate::getAnniversaryName() const
{
    return this->anniversaryName;
}
void AnniversaryDate::setAnniversaryName(std::string anniversaryname)
{
    this->anniversaryName = anniversaryname;
}

// 메인메뉴 목록을 출력하는 메소드, 이용할 메뉴의 번호를 반환한다.
int AnniversaryDate::mainMenu()
{
    int selectNumber{ 0 };
    std::cout << "[ 주소록 메인메뉴 입니다. 원하는 작업을 선택하세요. ]" << std::endl;
    std::cout << "1. 주소록 입력" << std::endl;
    std::cout << "2. 주소록 삭제" << std::endl;
    std::cout << "3. 주소록 검색" << std::endl;
    std::cout << "4. 모든 주소록 확인" << std::endl;
    std::cout << "9. 프로그램 종료" << std::endl;
    std::cout << " >>\t";
    std::cin >> selectNumber;

    return selectNumber;        // 선택한 번호를 리턴한다.
}

// 특정 주소록의 정보를 검색하는 메소드
void AnniversaryDate::searchData(std::vector<AnniversaryDate>& data)
{
    int selectNumber{ 0 };
    std::string searchName{ "홍길동" };
    std::string searchPhoneNumber{ "0" };

    int index{ -1 };    // 아무런 정보를 찾지 못했을 경우 -1로 설정함

    std::cout << "1. 이름으로 검색 2. 전화번호로 검색" << std::endl;
    std::cout << " >>\t";
    std::cin >> selectNumber;

    if (selectNumber == 1) {
        std::cout << "[ 이름으로 검색합니다. ]" << std::endl;
        std::cout << "이름을 입력해 주세요." << std::endl;
        std::cout << " >>\t";
        std::cin >> searchName;

        for (int i{ 0 }; i < data.size(); i++) {
            if (data[i].getName() == searchName) {
                index = i;      // 입력한 이름과 저장된 이름이 같으면 인덱스를 저장한다.
                break;          // 일치한 정보를 찾으면 반복문을 빠져나간다. 단, 중복 이름이 있을 경우 가장 처음 저장된 정보이다.
            }
        }
    }
    else if (selectNumber == 2) {
        std::cout << "[ 전화번호로 검색합니다. ]" << std::endl;
        std::cout << "전화번호를 입력해 주세요." << std::endl;
        std::cout << " >>\t";
        std::cin >> searchPhoneNumber;

        for (int i{ 0 }; i < data.size(); i++) {
            if (data[i].getPhoneNumber() == searchPhoneNumber) {
                index = i;
                break;
            }
        }
    }

    if (index == -1) {  // 인덱스가 -1이면 정보를 찾지 못했다는 의미이다.
        std::cout << "정보를 찾을 수 없습니다." << std::endl;
    }
    else {
        std::cout << "----- 검색한 정보입니다. -----" << std::endl;
        data[index].showAddress();  // 정보를 찾으면 출력
        std::cout << "생일            : "
            << data[index].getBirthYear() << "년 "
            << data[index].getBirthMonth() << "월 " << data[index].getBirthDay() << "일 " << std::endl;
        std::cout << "기념일 " << data[index].getAnniversaryName() << " : " << data[index].getAnniversaryYear() << "년 "
            << data[index].getAnniversaryMonth() << "월 " << data[index].getAnniversaryDay() << "일 " << std::endl;
        data[index].d_Day();        // D-day 출력
        std::cout << std::endl;
    }
}

// 선택한 주소록을 삭제하는 메소드
void AnniversaryDate::deleteData(std::vector<AnniversaryDate>& data)
{
    int selectNumber{ 0 };
    std::string searchName{ "홍길동" };
    std::string searchPhoneNumber{ "0" };

    int index{ -1 };

    std::vector<AnniversaryDate>::iterator iter = data.begin();  // 벡터의 시작 지점을 저장한 변수를 선언하였다.

    std::cout << "삭제할 주소록의 이름을 입력해 주세요." << std::endl;
    std::cout << " >>\t";
    std::cin >> searchName;

    std::cout << "삭제할 주소록의 전화번호를 입력해 주세요." << std::endl;
    std::cout << " >>\t";
    std::cin >> searchPhoneNumber;

    for (int i{ 0 }; i < data.size(); i++) {
        if (data[i].getName() == searchName) {
            if (data[i].getPhoneNumber() == searchPhoneNumber) {
                index = i;      // 동명이인을 방지하기 위해 이름과 전화번호 둘 다 일치하도록 만듦
                break;
            }
        }
    }

    if (index == -1) {          // 주소를 찾지 못해 -1의 값이 있으면 찾지 못했다는 구문 출력
        std::cout << "정보를 찾을 수 없습니다." << std::endl;
    }
    else {
        std::cout << "----- 삭제할 주소록입니다. -----" << std::endl;
        data[index].showAddress();      // 삭제할 주소록을 먼저 출력
        std::cout << std::endl;

        std::cout << "[ WARNINGS ] 주소록을 삭제하시겠습니까?" << std::endl;    // 삭제 다시 한번 확인
        std::cout << "1. 네 2. 아니오" << std::endl;
        std::cout << " >>\t";
        std::cin >> selectNumber;

        if (selectNumber == 1) {
            iter += index;      // 벡터의 시작 주소에서 검색한 인덱스만큼 이동한다.
            data.erase(iter);   // 벡터함수의 erase를 이용하여 선택된 인덱스를 삭제한다. 나머지 데이터들은 자동으로 붙는다.
            std::cout << "주소록을 삭제하였습니다." << std::endl;
        }
        else if (selectNumber == 2) {
            std::cout << "주소록 삭제를 취소하였습니다." << std::endl;
        }
    }

}

// 전체 주소록을 입력받는 메소드
void AnniversaryDate::intputData()
{
    int month[12] = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 }; // 입력받는 일 수를 제한하기 위한 배열

    inputAddress();         // 부모 클래스에 선언된 주소록을 입력하는 메소드를 호출
    std::cout << "생일 입력" << std::endl;
    do {
        std::cout << "년         : ";
        std::cin >> this->birthYear;
    } while (this->birthYear < 0);      // 음수를 입력받으면 다시 입력
    do {
        std::cout << "월         : ";
        std::cin >> this->birthMonth;
    } while (this->birthMonth > 12);    // 1년은 12월까지이기 때문에 12월 이상 입력받으면 다시 입력
    do {
        std::cout << "일         : ";
        std::cin >> this->birthDay;
    } while (this->birthDay > month[(this->birthMonth) - 1]); // 입력받은 월에 따라 달라짐
    std::cout << "기념일 입력" << std::endl;
    std::cout << "기념일 이름 : ";
    std::cin >> this->anniversaryName;
    do {
        std::cout << "년         : ";
        std::cin >> this->anniversaryYear;
    } while (this->anniversaryYear < 0);
    do {
        std::cout << "월         : ";
        std::cin >> this->anniversaryMonth;
    } while (this->anniversaryMonth > 12);
    do {
        std::cout << "일         : ";
        std::cin >> this->anniversaryDay;
    } while (this->anniversaryDay > month[(this->anniversaryMonth) - 1]);
}

// 전체 주소록을 출력하는 메소드
void AnniversaryDate::showData(std::vector<AnniversaryDate>& data)
{
    for (int i{ 0 }; i < data.size(); i++) {
        std::cout << i + 1 << " 번째 저장된 정보" << std::endl;
        data[i].showAddress();      // 부모 클래스에 입력된 주소록을 호출
        std::cout << "생일            : " 
            << data[i].getBirthYear() << "년 "
            << data[i].getBirthMonth() << "월 " << data[i].getBirthDay() << "일 " << std::endl;
        std::cout << "기념일 "<< data[i].getAnniversaryName() << " : "  << data[i].getAnniversaryYear() << "년 "
            << data[i].getAnniversaryMonth() << "월 " << data[i].getAnniversaryDay() << "일 " << std::endl;
        std::cout << "-----------------------------" << std::endl << std::endl;
    }
}

// D-day 계산 메소드
void AnniversaryDate::d_Day()
{
    /* 시간 함수 이용 */
    time_t timer = time(NULL);              // <ctime>에 저장된 함수를 이용하여 os가 제공하는 현재 시간을 대입 
    struct tm* t = localtime(&timer);       // 라이브러리에 정의된 구조체에 시간을 대입, 년/월/일을 쉽게 이용가능

    if (t->tm_mon == getBirthMonth() - 1) { // tm구조체에 저장된 month는 +1을 더해줘야 함
        if (t->tm_mday == getBirthDay()) {  // 생일의 월, 일이 같을 때 생일 축하 문구를 출력
            std::cout << " <Happy Birthday> 생일을 축하합니다~!! " << std::endl;
        }
    }
    // tm구조제에서 year을 사용할 때 1900을 더해줘야함
    if ((t->tm_year + 1900) > getAnniversaryYear()) {       // 지정된 년도가 현재 년도보다 느릴경우 기념일이 지남
        std::cout << " 기념일이 지났습니다. " << std::endl;
    }
    else if((t->tm_year + 1900) <= getAnniversaryYear()) {  
        if (t->tm_yday == changeMonthToDay()) {             // tm_yday는 1월 1일부터 어제까지의 일 수의 합
            std::cout << " 축하합니다 오늘이 기념일입니다. " << std::endl;
        }
        else if (t->tm_yday > changeMonthToDay()) {         // 오늘까지의 일수가 더 크면 날짜가 지났다는 의미
            std::cout << " 기념일이 지났습니다. " << std::endl;
        }
        else {                  // 내가 입력한 날짜 까지 일 수의 합에서 오늘까지 일 수의 합을 빼면 D-day
            std::cout << " 기념일까지 D- " << changeMonthToDay() - t->tm_yday << " 일 남았습니다." << std::endl;
            //std::cout << " 입력 받은 날짜 까지 " << changeMonthToDay() << std::endl;
            //std::cout << " 1월1일부터 오늘까지 " << t->tm_yday << std::endl;
        }
    }
}

// 입력한 년월일을 일 수로 변환하는 메소드
int AnniversaryDate::changeMonthToDay()
{
    /* 시간 함수 이용 */
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    int month[12] = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 };

    int dayTime{ 0 };
    int year{ 0 };
    int monthToDay{ 0 };

    for (uint32_t i{ getAnniversaryYear() }; i > (t->tm_year + 1900); i--) {
        if (getAnniversaryYear() % 4 == 0) {        // 윤년 체크
            year += 366;                            // 윤년이면 266일
        }
        else {
            year += 365;
        }
    }

    if (getAnniversaryYear() % 4 == 0) {        // 윤년 체크
        month[1] = 29;                          // 윤년이면 2월달은 29일이다.
    }
    for (int i{ 0 }; i < getAnniversaryMonth() - 1; i++) {
        monthToDay += month[i];
    }

    // 비교하는 tm_yday가 어제까지의 날짜 합이기 때문에 1을 빼준다.
    dayTime = year + monthToDay + (getAnniversaryDay() - 1);    

    return dayTime;
}
//
//void AnniversaryDate::currentTime()          // 현재 시간을 나타내는 함수
//{
//    /* 시간 함수 이용 */
//    time_t timer = time(NULL);
//    struct tm* t = localtime(&timer);
//
//    std::cout << "오늘 날짜 : " << t->tm_year + 1900 << "년 " << t->tm_mon + 1 << "월 "
//        << t->tm_mday << "일 " << std::endl;
//    std::cout << t->tm_yday << "일 " << std::endl;
//}