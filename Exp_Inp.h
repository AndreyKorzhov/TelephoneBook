#pragma once

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void Export_File(map<string,Person>&phoneBook,Person &person) {

    string tel;
    ofstream file_phone("phonebook.csv", ios_base::app);
    if (file_phone.is_open()) {

            file_phone << person.name << ";"
                       << person.surname << ";"
                       << person.main << ";"
                       << "Home" << person.tel1 << ";"
                       << "Work" << person.tel2 << ";"
                       << "Another" << person.tel3 << endl;


    } else {
        cout << "No open file_phone" << endl;

    }
    file_phone.close();
}
void Import_File (map<string,Person>&phoneBook) {

    string tel;
    Person person;
    ifstream file_phone("phonebook.csv");


    if (file_phone.is_open() && file_phone.peek()!=-1) {

        while (!file_phone.eof()) {

            getline(file_phone, person.name, ';');
            getline(file_phone, person.surname, ';');
            getline(file_phone, person.main, ';');
            getline(file_phone, person.tel1, ';');
            getline(file_phone, person.tel2, ';');
            getline(file_phone, person.tel3);
            tel=person.main;

            phoneBook.insert(pair<string,Person>(tel, person));
            //ShowData(phoneBook);
       }

    }  else {
        cout << "No open file_phone" << endl;
    }


    file_phone.close();
}
/*void ImportFromFile(map<string, Person>& phoneBook) {
    ifstream file;
    string address;

    cout << "Please, Enter The Address Of File" << endl;
    cin >> address;

    file.open(address);

    if (file.is_open() && file.peek() == -1) {
        cout << "File is empty. Please, try again" << endl;
    }
    else if (file.is_open() && file.peek() != -1) {
        Import_File(phoneBook);
        cout << "Adding students list from file is successful" << endl;
    }
    else {
        cout << "There is no such file. Please try again" << endl;
    }
    file.close();
}*/