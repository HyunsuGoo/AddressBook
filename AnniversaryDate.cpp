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

// ���θ޴� ����� ����ϴ� �޼ҵ�, �̿��� �޴��� ��ȣ�� ��ȯ�Ѵ�.
int AnniversaryDate::mainMenu()
{
    int selectNumber{ 0 };
    std::cout << "[ �ּҷ� ���θ޴� �Դϴ�. ���ϴ� �۾��� �����ϼ���. ]" << std::endl;
    std::cout << "1. �ּҷ� �Է�" << std::endl;
    std::cout << "2. �ּҷ� ����" << std::endl;
    std::cout << "3. �ּҷ� �˻�" << std::endl;
    std::cout << "4. ��� �ּҷ� Ȯ��" << std::endl;
    std::cout << "9. ���α׷� ����" << std::endl;
    std::cout << " >>\t";
    std::cin >> selectNumber;

    return selectNumber;        // ������ ��ȣ�� �����Ѵ�.
}

// Ư�� �ּҷ��� ������ �˻��ϴ� �޼ҵ�
void AnniversaryDate::searchData(std::vector<AnniversaryDate>& data)
{
    int selectNumber{ 0 };
    std::string searchName{ "ȫ�浿" };
    std::string searchPhoneNumber{ "0" };

    int index{ -1 };    // �ƹ��� ������ ã�� ������ ��� -1�� ������

    std::cout << "1. �̸����� �˻� 2. ��ȭ��ȣ�� �˻�" << std::endl;
    std::cout << " >>\t";
    std::cin >> selectNumber;

    if (selectNumber == 1) {
        std::cout << "[ �̸����� �˻��մϴ�. ]" << std::endl;
        std::cout << "�̸��� �Է��� �ּ���." << std::endl;
        std::cout << " >>\t";
        std::cin >> searchName;

        for (int i{ 0 }; i < data.size(); i++) {
            if (data[i].getName() == searchName) {
                index = i;      // �Է��� �̸��� ����� �̸��� ������ �ε����� �����Ѵ�.
                break;          // ��ġ�� ������ ã���� �ݺ����� ����������. ��, �ߺ� �̸��� ���� ��� ���� ó�� ����� �����̴�.
            }
        }
    }
    else if (selectNumber == 2) {
        std::cout << "[ ��ȭ��ȣ�� �˻��մϴ�. ]" << std::endl;
        std::cout << "��ȭ��ȣ�� �Է��� �ּ���." << std::endl;
        std::cout << " >>\t";
        std::cin >> searchPhoneNumber;

        for (int i{ 0 }; i < data.size(); i++) {
            if (data[i].getPhoneNumber() == searchPhoneNumber) {
                index = i;
                break;
            }
        }
    }

    if (index == -1) {  // �ε����� -1�̸� ������ ã�� ���ߴٴ� �ǹ��̴�.
        std::cout << "������ ã�� �� �����ϴ�." << std::endl;
    }
    else {
        std::cout << "----- �˻��� �����Դϴ�. -----" << std::endl;
        data[index].showAddress();  // ������ ã���� ���
        std::cout << "����            : "
            << data[index].getBirthYear() << "�� "
            << data[index].getBirthMonth() << "�� " << data[index].getBirthDay() << "�� " << std::endl;
        std::cout << "����� " << data[index].getAnniversaryName() << " : " << data[index].getAnniversaryYear() << "�� "
            << data[index].getAnniversaryMonth() << "�� " << data[index].getAnniversaryDay() << "�� " << std::endl;
        data[index].d_Day();        // D-day ���
        std::cout << std::endl;
    }
}

// ������ �ּҷ��� �����ϴ� �޼ҵ�
void AnniversaryDate::deleteData(std::vector<AnniversaryDate>& data)
{
    int selectNumber{ 0 };
    std::string searchName{ "ȫ�浿" };
    std::string searchPhoneNumber{ "0" };

    int index{ -1 };

    std::vector<AnniversaryDate>::iterator iter = data.begin();  // ������ ���� ������ ������ ������ �����Ͽ���.

    std::cout << "������ �ּҷ��� �̸��� �Է��� �ּ���." << std::endl;
    std::cout << " >>\t";
    std::cin >> searchName;

    std::cout << "������ �ּҷ��� ��ȭ��ȣ�� �Է��� �ּ���." << std::endl;
    std::cout << " >>\t";
    std::cin >> searchPhoneNumber;

    for (int i{ 0 }; i < data.size(); i++) {
        if (data[i].getName() == searchName) {
            if (data[i].getPhoneNumber() == searchPhoneNumber) {
                index = i;      // ���������� �����ϱ� ���� �̸��� ��ȭ��ȣ �� �� ��ġ�ϵ��� ����
                break;
            }
        }
    }

    if (index == -1) {          // �ּҸ� ã�� ���� -1�� ���� ������ ã�� ���ߴٴ� ���� ���
        std::cout << "������ ã�� �� �����ϴ�." << std::endl;
    }
    else {
        std::cout << "----- ������ �ּҷ��Դϴ�. -----" << std::endl;
        data[index].showAddress();      // ������ �ּҷ��� ���� ���
        std::cout << std::endl;

        std::cout << "[ WARNINGS ] �ּҷ��� �����Ͻðڽ��ϱ�?" << std::endl;    // ���� �ٽ� �ѹ� Ȯ��
        std::cout << "1. �� 2. �ƴϿ�" << std::endl;
        std::cout << " >>\t";
        std::cin >> selectNumber;

        if (selectNumber == 1) {
            iter += index;      // ������ ���� �ּҿ��� �˻��� �ε�����ŭ �̵��Ѵ�.
            data.erase(iter);   // �����Լ��� erase�� �̿��Ͽ� ���õ� �ε����� �����Ѵ�. ������ �����͵��� �ڵ����� �ٴ´�.
            std::cout << "�ּҷ��� �����Ͽ����ϴ�." << std::endl;
        }
        else if (selectNumber == 2) {
            std::cout << "�ּҷ� ������ ����Ͽ����ϴ�." << std::endl;
        }
    }

}

// ��ü �ּҷ��� �Է¹޴� �޼ҵ�
void AnniversaryDate::intputData()
{
    int month[12] = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 }; // �Է¹޴� �� ���� �����ϱ� ���� �迭

    inputAddress();         // �θ� Ŭ������ ����� �ּҷ��� �Է��ϴ� �޼ҵ带 ȣ��
    std::cout << "���� �Է�" << std::endl;
    do {
        std::cout << "��         : ";
        std::cin >> this->birthYear;
    } while (this->birthYear < 0);      // ������ �Է¹����� �ٽ� �Է�
    do {
        std::cout << "��         : ";
        std::cin >> this->birthMonth;
    } while (this->birthMonth > 12);    // 1���� 12�������̱� ������ 12�� �̻� �Է¹����� �ٽ� �Է�
    do {
        std::cout << "��         : ";
        std::cin >> this->birthDay;
    } while (this->birthDay > month[(this->birthMonth) - 1]); // �Է¹��� ���� ���� �޶���
    std::cout << "����� �Է�" << std::endl;
    std::cout << "����� �̸� : ";
    std::cin >> this->anniversaryName;
    do {
        std::cout << "��         : ";
        std::cin >> this->anniversaryYear;
    } while (this->anniversaryYear < 0);
    do {
        std::cout << "��         : ";
        std::cin >> this->anniversaryMonth;
    } while (this->anniversaryMonth > 12);
    do {
        std::cout << "��         : ";
        std::cin >> this->anniversaryDay;
    } while (this->anniversaryDay > month[(this->anniversaryMonth) - 1]);
}

// ��ü �ּҷ��� ����ϴ� �޼ҵ�
void AnniversaryDate::showData(std::vector<AnniversaryDate>& data)
{
    for (int i{ 0 }; i < data.size(); i++) {
        std::cout << i + 1 << " ��° ����� ����" << std::endl;
        data[i].showAddress();      // �θ� Ŭ������ �Էµ� �ּҷ��� ȣ��
        std::cout << "����            : " 
            << data[i].getBirthYear() << "�� "
            << data[i].getBirthMonth() << "�� " << data[i].getBirthDay() << "�� " << std::endl;
        std::cout << "����� "<< data[i].getAnniversaryName() << " : "  << data[i].getAnniversaryYear() << "�� "
            << data[i].getAnniversaryMonth() << "�� " << data[i].getAnniversaryDay() << "�� " << std::endl;
        std::cout << "-----------------------------" << std::endl << std::endl;
    }
}

// D-day ��� �޼ҵ�
void AnniversaryDate::d_Day()
{
    /* �ð� �Լ� �̿� */
    time_t timer = time(NULL);              // <ctime>�� ����� �Լ��� �̿��Ͽ� os�� �����ϴ� ���� �ð��� ���� 
    struct tm* t = localtime(&timer);       // ���̺귯���� ���ǵ� ����ü�� �ð��� ����, ��/��/���� ���� �̿밡��

    if (t->tm_mon == getBirthMonth() - 1) { // tm����ü�� ����� month�� +1�� ������� ��
        if (t->tm_mday == getBirthDay()) {  // ������ ��, ���� ���� �� ���� ���� ������ ���
            std::cout << " <Happy Birthday> ������ �����մϴ�~!! " << std::endl;
        }
    }
    // tm���������� year�� ����� �� 1900�� ���������
    if ((t->tm_year + 1900) > getAnniversaryYear()) {       // ������ �⵵�� ���� �⵵���� ������� ������� ����
        std::cout << " ������� �������ϴ�. " << std::endl;
    }
    else if((t->tm_year + 1900) <= getAnniversaryYear()) {  
        if (t->tm_yday == changeMonthToDay()) {             // tm_yday�� 1�� 1�Ϻ��� ���������� �� ���� ��
            std::cout << " �����մϴ� ������ ������Դϴ�. " << std::endl;
        }
        else if (t->tm_yday > changeMonthToDay()) {         // ���ñ����� �ϼ��� �� ũ�� ��¥�� �����ٴ� �ǹ�
            std::cout << " ������� �������ϴ�. " << std::endl;
        }
        else {                  // ���� �Է��� ��¥ ���� �� ���� �տ��� ���ñ��� �� ���� ���� ���� D-day
            std::cout << " ����ϱ��� D- " << changeMonthToDay() - t->tm_yday << " �� ���ҽ��ϴ�." << std::endl;
            //std::cout << " �Է� ���� ��¥ ���� " << changeMonthToDay() << std::endl;
            //std::cout << " 1��1�Ϻ��� ���ñ��� " << t->tm_yday << std::endl;
        }
    }
}

// �Է��� ������� �� ���� ��ȯ�ϴ� �޼ҵ�
int AnniversaryDate::changeMonthToDay()
{
    /* �ð� �Լ� �̿� */
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    int month[12] = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 };

    int dayTime{ 0 };
    int year{ 0 };
    int monthToDay{ 0 };

    for (uint32_t i{ getAnniversaryYear() }; i > (t->tm_year + 1900); i--) {
        if (getAnniversaryYear() % 4 == 0) {        // ���� üũ
            year += 366;                            // �����̸� 266��
        }
        else {
            year += 365;
        }
    }

    if (getAnniversaryYear() % 4 == 0) {        // ���� üũ
        month[1] = 29;                          // �����̸� 2������ 29���̴�.
    }
    for (int i{ 0 }; i < getAnniversaryMonth() - 1; i++) {
        monthToDay += month[i];
    }

    // ���ϴ� tm_yday�� ���������� ��¥ ���̱� ������ 1�� ���ش�.
    dayTime = year + monthToDay + (getAnniversaryDay() - 1);    

    return dayTime;
}
//
//void AnniversaryDate::currentTime()          // ���� �ð��� ��Ÿ���� �Լ�
//{
//    /* �ð� �Լ� �̿� */
//    time_t timer = time(NULL);
//    struct tm* t = localtime(&timer);
//
//    std::cout << "���� ��¥ : " << t->tm_year + 1900 << "�� " << t->tm_mon + 1 << "�� "
//        << t->tm_mday << "�� " << std::endl;
//    std::cout << t->tm_yday << "�� " << std::endl;
//}