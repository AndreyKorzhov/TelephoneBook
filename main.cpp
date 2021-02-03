#include <iostream>
#include <map>
#include "IO.h"
#include "Exp_Inp.h"

using namespace std;


int main() {
    map<string,Person> phoneBook;
    string tel;
    Person person;
    system ("chcp 65001");
    Welcome();
    int choice;
    bool flagExit = false;
    do {
        ShowMenu();
        cout << endl << "Введите пункт меню:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 1:
                InputData(phoneBook,person);
                Export_File(phoneBook,person);
                break;
            case 2:
                Import_File(phoneBook);
                Find(phoneBook,person);
                break;
            case 3:
                ShowData(phoneBook);
                break;
            case 4:
                Import_File(phoneBook);
                Redact(phoneBook, person);
                break;
            case 5:
                break;
            case 6:
                Export_File(phoneBook,person);
                break;
            case 7:
                Import_File(phoneBook);
                ShowData(phoneBook);
                break;
            case 0:
                flagExit=true;
                break;
            default:
                break;
        }
    }while (!flagExit);

    cout<<"До свидания!"<<endl;
}