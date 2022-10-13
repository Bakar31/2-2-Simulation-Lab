#include<iostream>
using namespace std;

int main()
{
    int a, count = 0;
    cout<<"Enter a number:"<<endl;
    cin>>a;

    for(int i =2; i<=a; i++)
    {
        if (a%i ==0)
        {
            count = count + 1;
        }
    }
    cout<<count<<endl;
    if (count ==1)
    {
        cout<<"Prime"<<endl;
    }
    else
    {
        cout<<"Not Prime";
    }
}
