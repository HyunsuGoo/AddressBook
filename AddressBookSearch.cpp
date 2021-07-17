// AddressBookSearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
/* 주소록 만들기 프로젝트 (class AddressBook)
    1. 이름       
    2. 전화번호
    3. 이메일
    4. 팩스번호
    5. 메모
    6. 생년월일 (#include <ctime>) : 검색 시 현재 생일이라면 "축하 문구"
    7. 기념일 (#include <ctime>) : 검색 시 현재 날짜와 차이 D-xxx
    (이름 전화번호 부모 - 나머지 상속 or 생일 기념일 부모 - 나머지 상속)
    -----------------------------------------------------------------
    1. 주소록 입력하기
    2. 주소록 삭제하기
    3. 검색 -> (1)이름 또는 (2)전화번호로 검색?
                생일 -> "축하문구"
                기념일 -> 현재 기념일이면 "기념일 알림", 아니면 남은 일수 D-xx
                이름, 이메일, 전화번호, 팩스번호, 메모 출력
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "AddressBook.h"
#include "AnniversaryDate.h"

int main()
{
    int selectMenu{ 0 };

    std::vector<AnniversaryDate> book;           // 벡터를 이용하여 입력 받을 때마다 배열 뒤에 저장 (queue)
    AnniversaryDate data{ AnniversaryDate() };    // 자식클래스 선언 및 기본값으로 초기화

    for (;;) {
        selectMenu = data.mainMenu();           // 메인메뉴에서 이용할 메뉴의 번호를 변수에 저장

        if (selectMenu == 1) {                  // 1번을 입력 받으면 주소록을 입력한다.
            std::cout << "-----정보를 입력합니다.-----" << std::endl;
            data.intputData();
            book.push_back(data);               // 벡터의 push_back 함수를 이용해 정보를 맨 끝에 저장
            std::cout << "현재 저장된 주소록 수 : " << book.size() << std::endl << std::endl;
        }
        // 2 ~ 4번은 주소록이 없을 경우 실행이 되지 않도록 따로 설정함
        else if (selectMenu == 2 || selectMenu == 3 || selectMenu == 4) {
            if (book.size() == 0) { // 메모리가 할당되지 않았을 때 (주소록이 없을 때) 출력문
                std::cout << "주소록에 저장된 정보가 없습니다!" << std::endl
                    << "주소록을 등록해 주세요!!!" << std::endl << std::endl;
            }
            else if (selectMenu == 2) { // 2번은 특정 주소록 삭제
                std::cout << std::endl << "-----주소록 삭제-----" << std::endl;
                data.deleteData(book);
            }
            else if (selectMenu == 3) { // 3번은 특정 주소록 검색
                std::cout << "-----주소록 검색-----" << std::endl << std::endl;
                data.searchData(book);
            }
            else if (selectMenu == 4) { // 4번은 주소록에 저장된 모든 정보를 불러옴
                std::cout << "-----저장된 주소록을 불러옵니다.-----" << std::endl << std::endl;
                std::cout << "총 주소록의 수 : " << book.size() << std::endl << std::endl;
                data.showData(book);
            }
        }
        else if (selectMenu == 9) { // 프로그램 완전 종료
            std::cout << "\r\n 프로그램을 종료합니다. " << std::endl << std::endl;
            break;
        }
        else {  // 다른 번호를 입력하면 실행불가 메시지를 출력
            std::cout << "잘못 입력하셨습니다." << std::endl << std::endl;
        }
    }
    
    //data.currentTime();       // <ctime> 라이브러리를 확인하기위한 임시 메소드

    return 0;
}