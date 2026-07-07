//链表有序 升序
#include<iostream>
using namespace std;
struct Listnode
{
    int data;
    Listnode *next;
};
void Union(Listnode *&Ah,Listnode *&At,Listnode *&Bh,Listnode *&Bt);
void PrintList(Listnode *&Ch,Listnode *&Ct);
int main()
{
    Listnode *head1 = new Listnode;
    Listnode *head2 = new Listnode;
    Listnode *tail1 = new Listnode;
    Listnode *tail2 = new Listnode;
    head1->next = tail1;
    head2->next = tail2;
    tail1->next = head1;
    tail2->next = head2;
    int i;
    Listnode *m1 = head1;
    Listnode *m2 = head2;
    for(i=0;i<10;i++)
    {
        Listnode *newnode1 = new Listnode;
        Listnode *newnode2 = new Listnode;
        
        newnode1->data = i+1;
        newnode1->next = tail1;
        m1->next = newnode1;
        m1 = newnode1;
        
        newnode2->data =(i+1)*10;
        newnode2->next = tail2;
        m2->next = newnode2;
        m2 = newnode2;
    }
    
    PrintList(head1,tail1);
    PrintList(head2,tail2);
    Union(head1,tail1,head2,tail2);
}

void PrintList(Listnode *&Ch,Listnode *&Ct)
{
    Listnode *temp;
    for(temp=Ch->next;temp!=Ct;temp=temp->next)
    {
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

void Union(Listnode *&Ah,Listnode *&At,Listnode *&Bh,Listnode *&Bt)//传入的是两个链表的头节点，尾节点
{
    //p,q直接指向第一个数据域
    Listnode *p = Ah->next;
    Listnode *q = Bh->next;
    Listnode *C = new Listnode;
    Listnode *r = C;
    Listnode *s = At;
    
    //前提条件：两个循环链表都没有到最后，两条链表之前本身是有序的，只要有一个跑完，则只需要连接一下就可以了
    while(p!=At && q!=Bt)
    {
        if(p->data < q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else if(p->data > q->data)
        {
            r->next = q;
            r = q;
            q = q->next;
        }
        else
        {
            r->next = p;
            r = p;
            p = p->next;
            q = q->next;
        }
    }
    //因为我的目的是就地取材，所以当合并完成后，原来的链表不存在了。课本上用的是妥妥的移花接木，不浪费内存的写法。
    //再加上我是将链表A的头当成新链表的头，所以A先遍历完和B先遍历完，最终成环的复杂程度是不一样的。同时完或者B先完，比较简单；但如果A先完，情况就复杂了
    if(p==At)
    {
        r->next = q;
        while(q->next!=Bt)//因为我是造了一个新的链表，所以不能像课本那样将就原来的
        {
            q = q->next;
        }
        q->next = s;
        
        //delete q;
    }
    else
    {
        r->next = p;
        while(p->next!=At)
        {
            p =p->next;
        }
        p->next = s;
    }
    s->next = C;//封闭这个链表
    PrintList(C,s);
}
/*
注意头指针 头节点 尾指针 尾节点的区别
*/
