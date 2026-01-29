#include<iostream>
using namespace std;
int main()
{
    int a = 100;
    int b = 300;
    //指针常量
    int *const p1 = &a;
    //常量指针
    const int *p2 = &a;
    
    *p1 = 200;
    cout<<*p1<<endl;
    p2 = &a;
    cout<<*p2<<endl;

}