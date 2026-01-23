#include<iostream>
#define num 6
int main()
{
    int a[num]={1,5,7,8,10,11};
    int i,m;
    for(i=0;i<=num/2;i++)
    {
        m = a[i];
        a[i] = a[num-i-1];
        a[num-i-1] = m;
    }
   for(i=0;i<=num-1;i++)
   {
        std::cout<<a[i]<<" ";
   }
}