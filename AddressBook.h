#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class AddressBook		// �θ� Ŭ����
{
private:				// Ŭ���� ��� �ν��Ͻ� ���� �� ����ȭ
	std::string name{ "ȫ�浿" };
	std::string phoneNumber{ "0" };
	std::string email{ "abcd@naver.com" };
	std::string faxNumber{ "0" };
	std::string memo{ "���� ����" };

public:
	AddressBook();			// ����Ʈ ������
	~AddressBook();			// �Ҹ���

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

	void inputAddress();	// �ּҷ��� �Է� �޴� �޼ҵ�
	void showAddress();		// �ּҷ��� ����ϴ� �޼ҵ�
};