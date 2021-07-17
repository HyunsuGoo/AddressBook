#pragma once
#include "AddressBook.h"
class AnniversaryDate :
    public AddressBook
{
private:                        // 클래스 멤버 인스턴스 선언 및 은닉화
    uint32_t birthYear{ 0U };
    uint32_t birthMonth{ 0U };
    uint32_t birthDay{ 0U };
    uint32_t anniversaryYear{ 0U };
    uint32_t anniversaryMonth{ 0U };
    uint32_t anniversaryDay{ 0U };
    std::string anniversaryName{ "0" };

public:
    uint32_t getBirthYear() const;
    void setBirthYear(uint32_t);
    uint32_t getBirthMonth() const;
    void setBirthMonth(uint32_t);
    uint32_t getBirthDay() const;
    void setBirthDay(uint32_t);
    uint32_t getAnniversaryYear() const;
    void setAnniversaryYear(uint32_t);
    uint32_t getAnniversaryMonth() const;
    void setAnniversaryMonth(uint32_t);
    uint32_t getAnniversaryDay() const;
    void setAnniversaryDay(uint32_t);
    std::string getAnniversaryName() const;
    void setAnniversaryName(std::string);

    int mainMenu();
    void searchData(std::vector<AnniversaryDate>&);  // 검색결과를 나타내는 메소드
    void deleteData(std::vector<AnniversaryDate>&);  // 주소록을 삭제하는 메소드

    void intputData();
    void showData(std::vector<AnniversaryDate>&);

    void d_Day();                                    // D-day를 출력하는 메소드
    int changeMonthToDay();                          // 입력한 날짜를 일 수로 변환하는 메소드

    //void currentTime();
};