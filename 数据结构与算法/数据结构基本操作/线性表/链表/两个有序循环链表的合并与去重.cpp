#include<iostream>
using namespace std;
struct Listnode{
    int data;
    Listnode *next;
    Listnode(int x):data(x),next(nullptr){};
};
class List{
    public:
    //创建带头节点的循环单链表
    Listnode *createcirclelist(vector<int> &m){
        
        if(m.empty()){
            return nullptr;
        }
        int i;
        Listnode *head = new Listnode(0);
        Listnode *p = head;
        for(i=0;i<m.size();i++){
            Listnode *newnode = new Listnode(m[i]);
            p->next = newnode;
            p = newnode;
        }
        Listnode *tail = p;
        tail->next = head;
        return head;
    }
    //打印带头节点的循环单链表
    void Printcirclelist(Listnode *head){
        Listnode *p = head->next;
        while(p!=head){
            cout<<p->data<<endl;
            p = p->next;
        }
    }
    //两个循环链表的合并与去重
    Listnode *Mergecirclelist(Listnode *A,Listnode *B){
        //拆分两个循环单链表，让他们不循环
        Listnode *tailA = A;
        while(tailA->next!=A){
            tailA = tailA->next;
        }
        tailA->next = nullptr;
        Listnode *tailB = B;
        while(tailB->next!=B){
            tailB = tailB->next;
        }
        tailB->next = nullptr;
        //合并两个拆分后的不循环的单链表
        Listnode *pA = A->next;
        Listnode *pB = B->next;
        //使用哨兵节点
        Listnode dummy(0);
        Listnode *tail = &dummy;
        while(pA && pB){
            if(pA->data < pB->data){
                tail->next = pA;
                pA = pA->next;
            }
            else if(pA->data > pB->data){
                tail->next = pB;
                pB = pB->next;
            }
            else{
                tail->next = pA;
                pA = pA->next;
                pB = pB->next;
            }
            tail = tail->next;
        }
        //当其中一个链表处理完的情况
        tail->next = (pA?pA:pB);
        //合并完成之后进行去重操作
        //采用双指针
        Listnode *head = dummy.next;
        Listnode *cur = head;
        while(cur && cur->next){
            if(cur->data == cur->next->data){
                Listnode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            else{
                cur = cur->next;
            }
        }
        tail = head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;
        return head;
    }
};