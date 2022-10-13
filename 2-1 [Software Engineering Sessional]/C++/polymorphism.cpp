#include<iostream>
#include<conio.h>

using namespace std;

class Person{
public:
    void display()
    {
        cout<<"Hello! I am a person"<<endl;
    }
};

class Student : public Person{

public:
    void display()
    {
        cout<<"Hello! I am a student"<<endl;
    }

};


class Teacher : public Person{

public:
    void display()
    {
        cout<<"Hello! I am a Teacher"<<endl;
    }

};


int main()
{
    Person p;
    Student s;
    Teacher t;
    p.display();
    s.display();
    t.display();
    return 0;
}
