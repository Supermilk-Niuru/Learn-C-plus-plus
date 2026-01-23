#include<iostream>
using namespace std;
int main()
{
    int pig[5]={100,150,140,120,130};
    int i,k;
    int max = pig[0];
    k = 0;
    for(i=1;i<=4;i++)
    {
        if(pig[i]>max)
        {
            max = pig[i];
            k = i;
        }
    }
    cout<<"体重最大的猪是第"<<k+1<<"只猪"<<",它的体重是"<<max<<"斤"<<endl;
}