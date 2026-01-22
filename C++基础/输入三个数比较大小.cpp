#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int max = a;
    if(b>max)
    {
        max = b;
    }
    if(c>max)
    {
        max = c;
    }
    cout<<max<<endl;
}