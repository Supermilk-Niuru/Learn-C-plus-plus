#include<iostream>
using namespace std;
struct Linklist
{
    int data;
    Linklist *next;
};
void delete_same_node(Linklist *&m)//传头指针进来，头指针指向头节点。
{
    Linklist *p = m->next;
    for(p;p->next!=NULL;p=p->next)//外层循环遍历整个链表 来最好是p->next != NULL;
    {
        //内层循环查找判断
        Linklist *q = p->next;
        Linklist *pre = p;//因为是单链表 所以要找到一个前驱
        for(q;q->next!=NULL;q=q->next)//来最好是q->next != NULL;
        {
            if(p->data==q->data)
            {
                pre->next = q->next;
                q = pre->next;//这个地方有问题 会造成漏检！！！所以最好是使用while循环
            }
            else
            {
                pre = pre->next;
            }
        }
    }
}