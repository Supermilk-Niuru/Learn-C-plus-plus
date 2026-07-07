#include<iostream>
#include<algorithm>
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
    //深度优先遍历求树的深度_非递归
    int DFS_Order(Binarytree *Node){
        if(Node == nullptr){
            return 0;
        }
        //栈中存储节点+当前深度
        stack<pair<Binarytree *,int>> s;
        s.push({Node,1});
        int maxdepth = 0;
        while(!s.empty()){
            //取栈顶元素并记录，然后删除栈顶元素
            auto m = s.top();
            s.pop();
            //分别记录栈顶元素各项的值
            Binarytree *newnode = m.first;
            int depth = m.second;
            //更新最大深度
            maxdepth = max(maxdepth,depth);
            //左孩子，右孩子分别入栈
            if(newnode->left){
                s.push({newnode->left,depth+1});
            }
            if(newnode->right){
                s.push({newnode->right,depth+1});
            }
        }
        return maxdepth;
    }
    Binarytree* Buildtree(vector<int> &m){
        if(m.size()==0||m[0]==-1){
            return nullptr;
        }
        //创建根节点
        Binarytree *Node = new Binarytree(m[0]);
        //借助队列创建二叉树
        queue<Binarytree *> q;
        q.push(Node);
        //继续构建子节点
        int i = 1;
        while(!q.empty()){
            Binarytree *newnode = q.front();
            q.pop();
            //左孩子
            if(i<m.size()&&m[i]!=-1){
                newnode->left = new Binarytree(m[i]);
                q.push(newnode->left);
            }
            i++;
            //右孩子
            if(i<m.size()&&m[i]!=-1){
                newnode->right = new Binarytree(m[i]);
                q.push(newnode->right);
            }
            i++;
        }
        return Node;
    }
    public:
    Tree_Order(vector<int> &m){
        T = Buildtree(m);
    }
    int DFS_Order(){
        return DFS_Order(T);
    }
};
int main(){
    vector<int> m = {1,2,3,4,5,6};
    Tree_Order tree(m);
    cout<<tree.DFS_Order()<<endl;
}