#include <iostream>
#include <Windows.h>
using namespace std;

//class Date {
//    uint16_t day;
//    uint16_t month;
//    uint16_t year;
//public:
//    Date(uint16_t day1, uint16_t month1, uint16_t year1) : day{day1}, month{month1}, year{year1} {}
//};

class People {
    int ID;
    const char* surname;
    const char* name;
    const char* patronymic;
    /*Date data;*/


public:
    People(int IDP, const char* surnameP, const char* nameP, const char* patronymicP/*, Date dataP*/) : ID{ IDP }, surname{ surnameP }, name{ nameP }, patronymic{ patronymicP }/*, data{ dataP }*/
    {cout << "Конструктор з параметрами\n"; }

    People() : ID{ 0 }, surname{ nullptr }, name{ nullptr }, patronymic{ nullptr }/*, data{ 0, 0, 0 }*/
    {cout << "Конструктор за замовчуванням\n"; }

    void ounput () {
        cout << "ID: " << ID <<"\nФамилия: " << surname << "\nИмя: " << name << "\nОтчество: " << patronymic /*<< "\nДата рождения: " << data*/;
    }
    ~People() {
        delete[] surname;
        delete[] name;
        delete[] patronymic;
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //char* surname = new char[sizeof("surname") / sizeof(char) + 1];
    //char* name = new char[sizeof("name") / sizeof(char) + 1];
    //char* patronymic = new char[sizeof("patronymic") / sizeof(char) + 1];
    //strcat_s(surname, sizeof("surname") / sizeof(char) + 1, "surname");
    People example1();
    Date data(0, 0, 0);
    People example2(12345, "Легеза", "Виталина", "Андреевна", data);

    example2.ounput();

}

