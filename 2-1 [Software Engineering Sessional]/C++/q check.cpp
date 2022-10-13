#include<iostream>
using namespace std;

int main()
{
    int var = 4;
    {
        int var = 3;
        cout<<var<<endl;
    }
    cout<<var<<endl;
    return 0;
}
