/*
给定两个有序链表 两降序变升序
升序合并升序
降序合并降序
降序合并升序
升序合并降序
*/
#include<iostream>
using namespace std;
struct Listnode
{
    int data;
    Listnode *next;
};
int main()
{
    Listnode *head1 = NULL;
    Listnode *head2 = NULL;
    int i;
    //创建有序链表m1
    for(i=0;i<10;i++)
    {
        Listnode *m1 = new Listnode;
        m1->data = (i+1)*10;
        m1->next = head1;
        head1 = m1;
    }
    //创建有序链表m2
    for(i=0;i<2;i++)
    {
        Listnode *m2 = new Listnode;
        m2->data = (i+1)*5;
        m2->next = head2;
        head2 = m2;
    }
    Listnode *temp;
    for(temp=head1;temp!=NULL;temp=temp->next)
    {
        cout<<temp->data<<" ";
    }
    cout<<endl;
    //Listnode *temp;
    for(temp=head2;temp!=NULL;temp=temp->next)
    {
        cout<<temp->data<<" ";
    }
    cout<<endl;
    //设置一个新链表，用来存储最后合并后的数据
    Listnode *head = new Listnode;
    head->next = NULL;
    Listnode *p,*q;//p间接m1，q间接m2
    p = head1;
    q = head2;
    while(p!=NULL||q!=NULL)//重点想明白
    {
        if(p != NULL && (q == NULL || p->data > q->data))//重点想明白
        {
            head1 = p->next;
            p->next = head->next;
            head->next = p;
            p = head1;
        }
        else//（q!=NULL&&(p==NULL||p->data>q->data)的情况
        {
            head2 = q->next;
            q->next = head->next;
            head->next = q;
            q = head2;
        }
    }
    //Listnode *temp;
    for(temp=head->next;temp!=NULL;temp=temp->next)//重点想明白
    {
        cout<<temp->data<<" ";
    }
    cout<<endl;
}
