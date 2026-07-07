#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}NODE;
void sort_again(NODE *h) 
{
    if (h == NULL || h->next == NULL) 
    {
        return;
    }
    // 找中点
    NODE *slow = h, *fast = h;
    while (fast->next != NULL) 
    {
        slow = slow->next;       
        fast = fast->next;
        if (fast->next != NULL) 
        {
            fast = fast->next; //也就是说，当没有到最后的时候，每次fast走两步，当到最后的时候，slow指向的就是中间节点
        }
    } 
    NODE *p = slow->next; 
    slow->next = NULL;
    NODE *pre = NULL, *current = p, *thenext;
    //中间往后 就地逆置
    while (current != NULL) 
    { 
        thenext = current->next;
        current->next = pre;
        pre = current;
        current = thenext;
    }
    NODE *p_front = h->next; 
    NODE *p_back = pre;      
    NODE *temp;
    //交替插入
    while (p_back != NULL) 
    {
        temp = p_back->next;     
        p_back->next = p_front->next; 
        p_front->next = p_back;
        p_front = p_back->next;  
        p_back = temp;//？？？       
    }
}