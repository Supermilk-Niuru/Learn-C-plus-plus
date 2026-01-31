#include<iostream>
#include<string>
#define num 4
using namespace std;
struct person
{
    string name;
    int age;
};
void Bubblesort(struct person *s);
void Printarr(struct person *s);
int main()
{
    struct person arr[num]={{"zhang",25},{"wang",18},{"liu",20},{"li",99}};
    Bubblesort(arr);
    Printarr(arr);
}
void Bubblesort(struct person *s)
{
    int i,j;
    for(i=0;i<num;i++)
    {
        bool flag = false;
        for(j=0;j<num-i-1;j++)
        {
            if(s[j].age>s[j+1].age)
            {
                struct person tmp;
                tmp.age = s[j].age;
                tmp.name = s[j].name;
                s[j].age = s[j+1].age;
                s[j].name = s[j+1].name;
                s[j+1].age = tmp.age;
                s[j+1].name = tmp.name;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
}
void Printarr(struct person *s)
{
    int i;
    for(i=0;i<num;i++)
    {
        cout<<s[i].name<<" "<<s[i].age<<endl;
    }
}