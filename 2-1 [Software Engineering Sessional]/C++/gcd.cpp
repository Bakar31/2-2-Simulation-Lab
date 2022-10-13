#include <iostream>
using namespace std;

int main()
{
    int a, b, r;
    cin>> a>>b;
    int p = a;
    int q = b;

    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    int gcd = a;
    cout<<a<<endl;
}
