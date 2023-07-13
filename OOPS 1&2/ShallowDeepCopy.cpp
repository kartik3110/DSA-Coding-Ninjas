#include <iostream>
#include <cstring>
using namespace std;
class student
{
private:
    int age;
    char *name; // cant do char* name = new char[100] as size is unknown.

public:
    student(int age, char *argname)
    {
        this->age = age;
        // shallow copy
        //   this->name = argname;

        // deep copy
        name = new char[strlen(argname) + 1]; //+1 for a null character
        strcpy(name, argname);
    }
    void print()
    {
        cout << "age: " << age << " "
             << "name: " << name << endl;
    }
};

int main()
{
    char name[] = "kartik";
    student s1(20, name);
    s1.print();
    name[2] = 'b';
    student s2(30, name);
    s1.print();

    return 0;
}