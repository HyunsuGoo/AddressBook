#include "AddressBook.h"
AddressBook::AddressBook() {}
AddressBook::~AddressBook() {}

std::string AddressBook::getName() const
{
	return this->name;
}
void AddressBook::setName(std::string name)
{
	this->name = name;
}
std::string AddressBook::getPhoneNumber() const
{
	return this->phoneNumber;
}
void AddressBook::setPhoneNumber(std::string phonenumber)
{
	this->phoneNumber = phonenumber;
}
std::string AddressBook::getEMail() const
{
	return this->email;
}
void AddressBook::setEMail(std::string email)
{
	this->email = email;
}
std::string AddressBook::getFaxNumber() const
{
	return this->faxNumber;
}
void AddressBook::setFaxNumber(std::string faxnumber)
{
	this->faxNumber = faxnumber;
}
std::string AddressBook::getMemo() const
{
	return this->memo;
}
void AddressBook::setMemo(std::string memo)
{
	this->memo = memo;
}

void AddressBook::inputAddress()		// 주소록 입력 메소드
{
	std::cout << "이름		: ";
	std::cin >> this->name;
	std::cout << "전화번호	: ";
	std::cin >> this->phoneNumber;
	std::cout << "이메일		: ";
	std::cin >> this->email;
	std::cout << "팩스번호	: ";
	std::cin >> this->faxNumber;
	std::cout << "메모		: ";
	std::cin >> this->memo;
}

void AddressBook::showAddress()		// 저장된 주소록을 출력하는 메소드
{
	std::cout << "이름		: " << this->name << std::endl;
	std::cout << "전화번호	: " << this->phoneNumber << std::endl;
	std::cout << "이메일		: " << this->email << std::endl;
	std::cout << "팩스번호	: " << this->faxNumber << std::endl;
	std::cout << "메모		: " << this->memo << std::endl;
}