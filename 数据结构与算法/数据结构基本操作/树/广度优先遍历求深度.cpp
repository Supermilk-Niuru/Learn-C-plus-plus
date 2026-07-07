#include<iostream>
#include<queue>
using namespace std;
struct Binarytree{
    int data;
    Binarytree *left;
    Binarytree *right;
    Binarytree(int x):data(x),left(nullptr),right(nullptr){};
};
class Tree_Order{
    private:
    Binarytree *T;
    int BFS_Order(Binarytree *Node){
        //广度优先遍历，借助队列实现
        //首先判断树是否为空
        if(Node == nullptr){
            return 0;
        }
        int depth = 0;
        //根节点入队列
        queue<Binarytree *> q;
        q.push(Node);
        while(!q.empty()){
            //得到每一层的节点数
            int level = q.size();
            int i;
            for(i=0;i<level;i++){
                //设置一个临时节点存储队头元素，弹出队头元素
                Binarytree *newnode = q.front();
                q.pop();
                //将该队头的子节点入队列
                if(newnode->left){
                    q.push(newnode->left);
                }
                if(newnode->right){
                    q.push(newnode->right);
                }
            }
            //每一层遍历完之后深度+1；
            depth++;
        }
        return depth;
    }
    public:
    Tree_Order(Binarytree *Node){
        T = Node;
    }
    int BFS_Order(){
        return BFS_Order(T);
    }
};
int main(){
    Binarytree *Node = new Binarytree(10);
    Node->left = new Binarytree(20);
    Node->right = new Binarytree(30);
    Tree_Order tree(Node);
    cout<<tree.BFS_Order()<<endl;
}