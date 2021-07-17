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

void AddressBook::inputAddress()		// �ּҷ� �Է� �޼ҵ�
{
	std::cout << "�̸�		: ";
	std::cin >> this->name;
	std::cout << "��ȭ��ȣ	: ";
	std::cin >> this->phoneNumber;
	std::cout << "�̸���		: ";
	std::cin >> this->email;
	std::cout << "�ѽ���ȣ	: ";
	std::cin >> this->faxNumber;
	std::cout << "�޸�		: ";
	std::cin >> this->memo;
}

void AddressBook::showAddress()		// ����� �ּҷ��� ����ϴ� �޼ҵ�
{
	std::cout << "�̸�		: " << this->name << std::endl;
	std::cout << "��ȭ��ȣ	: " << this->phoneNumber << std::endl;
	std::cout << "�̸���		: " << this->email << std::endl;
	std::cout << "�ѽ���ȣ	: " << this->faxNumber << std::endl;
	std::cout << "�޸�		: " << this->memo << std::endl;
}