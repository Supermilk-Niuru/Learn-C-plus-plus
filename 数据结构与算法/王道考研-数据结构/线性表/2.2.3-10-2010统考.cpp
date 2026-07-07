#include<iostream>
#include<vector>
using namespace std;
void Reverse(vector<int> &R, int left, int right) 
{
    while (left < right) 
    {
        int temp = R[left];
        R[left] = R[right];
        R[right] = temp;
        left++;
        right--;
    }
}
void Converse(vector<int> &R, int n, int p) 
{
    p = p % n; 
    if (p == 0) return;

    Reverse(R, 0, p - 1);     
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}
