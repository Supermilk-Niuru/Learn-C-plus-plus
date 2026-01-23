#include<iostream>
using namespace std;
int main()
{
    int i;
    for(i=1;i<=100;i++)
    {
        if(i%10==7||i/10==7)
        {
            cout<<i<<" ";
        }
        else if (i%7==0)
        {
            cout<<i<<" ";
        }
        else
        {
            continue;
        }
    }
}