#include<iostream>
using namespace std;
struct Binarytree{
    int data;
    Binarytree *left;
    Binarytree *right;
    //添加构造函数
    Binarytree(int x):data(x),left(nullptr),right(nullptr){};
};
class Tree_Order{
    private:
    Binarytree *T;
    int DFS_Order(Binarytree *Node){
        if(Node == nullptr){
            return 0;
        }
        int left = DFS_Order(Node->left);
        int right = DFS_Order(Node->right);
        int MAX = max(left,right);
        return MAX+1;
    }
    public:
    Tree_Order(Binarytree *Node){
        T = Node;
    }
    int DFS_Order(){
        return DFS_Order(T);
    }
};
int main(){
    Binarytree *Node = new Binarytree(10);
    Node->left = new Binarytree(20);
    Node->right = new Binarytree(30);
    Tree_Order tree(Node);
    cout<<tree.DFS_Order()<<endl;
}