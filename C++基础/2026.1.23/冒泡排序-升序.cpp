#include<iostream>
#define num 10
using namespace std;
int main()
{
    int a[num] = {1,3,4,6,8,9,10,7,2,5};
    int i,j;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num-i-1;j++)//为什么不是"<="(越界，num-1-i之后的已经排好了)，为什么从j=0开始(冒泡排序是后面是有序的，前面是无序的，故从a[0]开始)。
        {
            int k;
            if(a[j]>a[j+1])
            {
                k = a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    for(i=0;i<num;i++)
    {
        cout<<a[i]<<" ";
    }
}