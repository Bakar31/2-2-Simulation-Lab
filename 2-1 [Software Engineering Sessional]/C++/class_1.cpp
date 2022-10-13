#include<iostream>
using namespace std;

class MyClass{
    int a;

public:
    void set_a(int num);
    int get_a();
};

void MyClass::set_a(int num)
{
    a = num;
}

int MyClass::get_a()
{
    return a;
}

int main()
{
    MyClass class1, class2;
    class1.set_a(31);
    cout<<class1.get_a()<<endl;

    class2.set_a(35);
    cout<<class2.get_a()<<endl;

}
