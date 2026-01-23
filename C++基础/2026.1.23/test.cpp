#include<iostream>
using namespace std;
int main()
{
    int arr[10]={0};
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(arr[0])<<endl;
    cout<<sizeof(arr)/sizeof(int)<<endl;
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<&arr[1]<<endl;
    cout<<(long int)(arr)<<endl;
    //cout<<sizeof(long int)<<" "<<sizeof(long long int)<<" "<<sizeof(int)<<endl;
}