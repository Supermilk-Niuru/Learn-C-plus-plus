#include<iostream>
using namespace std;
int main()
{
    int i=1;
    do
    {
        if(i%10==1&&i!=1)
        {
            cout<<endl;
        }
        cout<<"*";
        i++;
    } while (i<=100);
    
}