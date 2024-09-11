#include <iostream>
#include <Windows.h>
using namespace std;

class Date {
    uint16_t day;
    uint16_t month;
    uint16_t year;
public:
    Date(uint16_t day1, uint16_t month1, uint16_t year1) : day{ day1 }, month{ month1 }, year{ year1 } {}
    Date() : Date(0, 0, 0) { }

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
    static int count;


public:

    People(int IDP, const char* surnameP, const char* nameP, const char* patronymicP, Date dataP) : ID{ IDP }, data{ dataP }
    {
        surname = new char[20];
        name = new char[20];
        patronymic = new char[20];

        strcpy_s(surname, 20, surnameP);
        strcpy_s(name, 20, nameP);
        strcpy_s(patronymic, 20, patronymicP);

        cout << "Конструктор с параметрами\n";

        count++;
    }

    People() : People(0, " ", " ", " ", Date{ 0, 0, 0 }) {
        cout << "Конструктор по умолчанию\n";
    }

    ~People() {
        delete[] surname;
        delete[] name;
        delete[] patronymic;

        count--;
    }

    People(const People& object)
        : ID{ object.ID }, data{ object.data } {
        surname = new char[strlen(object.surname) + 1];
        strcpy_s(surname, strlen(object.surname) + 1, object.surname);

        name = new char[strlen(object.name) + 1];
        strcpy_s(name, strlen(object.name) + 1, object.name);

        patronymic = new char[strlen(object.patronymic) + 1];
        strcpy_s(patronymic, strlen(object.patronymic) + 1, object.patronymic);

        count++;
        cout << "Конструктор копирования " << this << "\n";
    }


    int getID() { return ID; }
    void setID(int IDp) { ID = IDp; }
    const char* getsurname() { return surname; }
    void setsurname(const char* surnameP) {
        delete[] surname;
        surname = new char[sizeof(surnameP) + 1];
        strcpy_s(surname, sizeof(surnameP) + 1, surnameP);
    }
    const char* getname() { return name; }
    void setname(const char* nameP) {
        delete[] name;
        name = new char[sizeof(nameP) + 1];
        strcpy_s(name, sizeof(nameP) + 1, nameP);
    }
    const char* getpatronymic() { return patronymic; }
    void setpatronymic(const char* patronymicP) { 
        delete[] patronymic;
        patronymic = new char[sizeof(patronymicP) + 1];
        strcpy_s(patronymic, sizeof(patronymicP) + 1, patronymicP);
    }

    void output() const {
        cout << endl << "ID: " << ID << "\nФамилия: " << (surname ? surname : " ") << "\nИмя: " << (name ? name : " ") << "\nОтчество: " << (patronymic ? patronymic : " ") << "\nДата рождения: ";
        data.printDate();
        cout << endl;
    }

    static int getCount() { return count; }
};

int People::count =0;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    People example1;
    Date data(9, 12, 2006);
    People example2(12345, "Легеза", "Виталина", "Андреевна", data);
    People example3 = example2;

    example1.output();
    example2.output();
    example3.output();

    cout<< endl << "Количество People: " << People::getCount() << endl;

    return 0;
}
