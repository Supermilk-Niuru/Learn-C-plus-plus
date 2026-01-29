#include<iostream>
using namespace std;
void bubblesort(int *arr,int len);
void arrayprint(int *arr,int len);
int main()
{
    int arr[] = {2,89,87,92,67,99,101,78,86,77};
    int len = sizeof(arr)/sizeof(int);
    bubblesort(arr,len);
    arrayprint(arr,len);
}

void bubblesort(int *arr,int len)
{
    int i,j;
    bool flag = false;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
}

void arrayprint(int *arr,int len)
{
    int i;
    int *p = arr;
    for(i=0;i<len;i++)
    {
        cout<<*p<<" ";
        p++;
    }
}