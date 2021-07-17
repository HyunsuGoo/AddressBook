#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class AddressBook		// 부모 클래스
{
private:				// 클래스 멤버 인스턴스 선언 및 은닉화
	std::string name{ "홍길동" };
	std::string phoneNumber{ "0" };
	std::string email{ "abcd@naver.com" };
	std::string faxNumber{ "0" };
	std::string memo{ "내용 없음" };

public:
	AddressBook();			// 디폴트 생성자
	~AddressBook();			// 소멸자

	std::string getName() const;
	void setName(std::string);
	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string);
	std::string getEMail() const;
	void setEMail(std::string);
	std::string getFaxNumber() const;
	void setFaxNumber(std::string);
	std::string getMemo() const;
	void setMemo(std::string);

	void inputAddress();	// 주소록을 입력 받는 메소드
	void showAddress();		// 주소록을 출력하는 메소드
};