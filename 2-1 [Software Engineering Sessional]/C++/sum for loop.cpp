#include<iostream>
using namespace std;

int main()
{
    int i , j, sum = 0;
    sum = 0;
    cout<<"Enter start value:"<<endl;
    cin>>i;
    cout<<"Enter end value:"<<endl;
    cin>>j;
    for(i; i<=j; i++)
    {
        sum = sum + i;
    }
    cout<<sum<<endl;
}
