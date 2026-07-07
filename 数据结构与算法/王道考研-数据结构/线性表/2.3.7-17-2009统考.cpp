#include <iostream>
using namespace std;
typedef struct node 
{
    int data;
    struct node *link;
} NODE;
int find_data(NODE *list, int k) 
{
    NODE *p = list->link; 
    NODE *q = list->link; 
    int count = 0;
    while (p != NULL && count < k) 
    {
        p = p->link;
        count++;
    }
    if (count < k)//就是遍历到末尾时，还没达到预期的位置
    {
        return 0; 
    }
    while (p != NULL)
     {
        p = p->link;
        q = q->link;
    }
    cout << q->data << endl;
    return 1;
}