#include<iostream>
using namespace std;
int main()
{
    int num = rand()%100+1;
    //cout<<num<<endl;
    int c;
    cin>>c;
    while(c!=num)
    {
        if(c<num)
        {
            cout<<"small"<<endl;
            cin>>c;
        }
        else
        {
            cout<<"big"<<endl;
            cin>>c;
        }
    }
    cout<<"yes "<<c<<endl;
}