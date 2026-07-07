#include<iostream>//前提是已经定下来 必定有相同的后缀
using namespace std;
struct LNode 
{
    char data;
    struct LNode *next;
};
int length(LNode *&head) 
{
    int len = 0;
    LNode *p = head->next; 
    while (p!= NULL) 
    {
        len++;
        p = p->next;
    }
    return len;
}
LNode *same(LNode *&str1, LNode *&str2) 
{
    int len1 = length(str1);
    int len2 = length(str2);
    LNode *p = str1->next;
    LNode *q = str2->next;
    //消除长度差
    if (len1 > len2) 
    {
        for (int i = 0; i < len1 - len2; i++) 
        {
            p = p->next;
        }
    } 
    else 
    {
        for (int i = 0; i < len2 - len1; i++) 
        {
            q = q->next;
        }
    }
    while (p!=NULL && p!=q || q!=NULL && q!=p) 
    {
        p = p->next;
        q = q->next;
    }
    if(len1 > len2)
    {
        return p; 
    }
    else
    {
        return q;
    }
}