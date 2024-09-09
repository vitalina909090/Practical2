#include <iostream>
#include <Windows.h>
using namespace std;

class Date {
    uint16_t day;
    uint16_t month;
    uint16_t year;
public:
    Date(uint16_t day1, uint16_t month1, uint16_t year1) : day{ day1 }, month{ month1 }, year{ year1 } {}

    void printDate() const {
        cout << (day < 10 ? "0" : "") << day << "-" << (month < 10 ? "0" : "") << month << "-" << year;
    }
};

class People {
    int ID;
    char* surname;
    char* name;
    char* patronymic;
    Date data;

public:
    People(int IDP, const char* surnameP, const char* nameP, const char* patronymicP, Date dataP): ID{ IDP }, data{ dataP } 
    {
        surname = new char[20];  
        name = new char[20];    
        patronymic = new char[20]; 

        strcpy_s(surname, 20, surnameP);
        strcpy_s(name, 20, nameP);
        strcpy_s(patronymic, 20, patronymicP);

        cout << "Конструктор с параметрами\n";
    }

    People() : ID{ 0 }, surname{ nullptr }, name{ nullptr }, patronymic{ nullptr }, data{ 0, 0, 0 } {
        cout << "Конструктор по умолчанию\n";
    }

    ~People() {
        delete[] surname;
        delete[] name;
        delete[] patronymic;
    }

    void output() const {
        cout << "ID: " << ID << "\nФамилия: " << (surname ? surname : " ") << "\nИмя: " << (name ? name : " ") << "\nОтчество: " << (patronymic ? patronymic : " ") << "\nДата рождения: ";
        data.printDate();
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    People example1;  
    Date data(9, 12, 2006);
    People example2(12345, "Легеза", "Виталина", "Андреевна", data);

    example1.output();
    example2.output();

    return 0;
}