#include <iostream>
#include <string>
#include "Person.h"


using namespace std;

void Welcome(){
    cout<<"===================="<<endl;
    cout<<"=== PhoneBook ==="<<endl;
    cout<<"=(c) IT Step ======="<<endl;
    cout<<"===================="<<endl;
}
void ShowMenu(){
    cout<<"Пункты меню:"<<endl;
    cout<<"1. Добавить новый контакт "<<endl;
    cout<<"2. Поиск контакта "<<endl;
    cout<<"3. Показ всех контактов "<<endl;
    cout<<"4. Редактировать контакт" <<endl;
    cout<<"5. Удалить контакт "<<endl;
    cout<<"6. Экспорт в файл "<<endl;
    cout<<"7. Импорт из файла"<<endl;
    cout<<endl;
    cout<<"0. Выход "<<endl;
}
void InputStructure (Person &person){
    cout<<"Enter name - ";
    cin>>person.name;
    cout<<"Enter surname - ";
    cin>>person.surname;
    char extratel1;
    cout<<"Enter '+' for add an extra number; enter other symbol  for skip   ";
    cin>>extratel1;
    if (extratel1 == '+') {
        cout << "Enter extra number - ";
        cin >> person.tel1;
    }
    else {
        person.tel1 = "________";
        person.tel2 = "________";
        person.tel3 = "________";
    goto link;
    }
    char extratel2;
    cout<<"Enter '+' for add an extra number; enter other symbol  for skip   ";
    cin>>extratel2;
    if (extratel2 == '+') {
        cout << "Enter extra number - ";
        cin >> person.tel2;
    } else
    {
        person.tel2 = "________";
        person.tel3 = "________";
        goto link;
    }
    char extratel3;
    cout<<" Enter '+' for add an extra number; enter other symbol  for skip   ";
    cin>>extratel3;
    if (extratel3 == '+') {
        cout << "Enter extra number - ";
        cin >> person.tel3;
    }
    else
        {  person.tel3 = "________";
        goto link;
    }
    link: cout << endl;
}

void InputData(map<string,Person>& phonebook,Person& person){
    string tel;
    cout<<"Enter telephone number - ";
    cin>>tel;
    person.main = tel;
    InputStructure(person);
    phonebook.insert(pair<string,Person>(tel,person));
}

void ShowData(map<string,Person> &phonebook){
    for( auto element : phonebook)
    {
        cout    << "--- Person ---" << endl;
        cout    << "Name : " << element.second.name <<"\n"
                << "Surname : " << element.second.surname <<"\n"
                << "Main number : " << element.second.main <<"\n"
                << "Home number : " << element.second.tel1 <<"\n"
                << "Work number : " << element.second.tel2 <<"\n"
                << "Another number : " << element.second.tel3 << "\n\n\n\n";
    }
}
void Find(map<string,Person> phonebook, Person& person)
{

    string tel;
    cout<<"Enter main telephone - "<<endl;
    cin>>tel;
   // map<string,Person>::iterator iter =phonebook.find("tel");

    auto it = phonebook.find(tel);

    if (it!= phonebook.end())
    {
        person  = it-> second;
    }

    cout    << "--- Person ---" << endl;
    cout    << "Main number : " << tel << "\n"
            << "Name : " << person.name <<"\n"
            << "Surname : " << person.surname <<"\n"
            << "Main number : " << person.main <<"\n"
            << "Home number : " << person.tel1 <<"\n"
            << "Work number : " << person.tel2 <<"\n"
            << "Another number : " << person.tel3 << "\n\n\n\n";
}
void Redact(map<string,Person>& phonebook, Person& person){
    string tel;
    cout<<"Enter main telephone - "<<endl;
    cin>>tel;
    //map<string,Person>::iterator iter =phonebook.find("tel");
    auto it = phonebook.find(tel);
    if (it!= phonebook.end())
    {
        person  = it-> second;
    }
    cout    << "--- Person redact  ---" << endl;
    cout    << "Main number : " << tel<<endl;
    cout      << "Name : " <<endl;cin>> person.name ;
    cout      << "Surname : " <<endl;cin>> person.surname;
    cout      << "Main number : " <<endl;cin>> person.main ;
    cout      << "Home number : " << endl;cin>>person.tel1 ;
    cout      << "Work number : " <<endl;cin>> person.tel2 ;
    cout      << "Another number : "<<endl ;cin>> person.tel3;
}
