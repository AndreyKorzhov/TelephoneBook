#include <string>

using namespace std;

struct Telephones
{
    string tel_home;
    string tel_work;
    string tel_other;
};
struct Person
{
    string firstname;
    string lastname;
    Telephones telephone_numbers;
    string group;
};

