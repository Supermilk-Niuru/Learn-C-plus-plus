#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode{
    char val;
    TreeNode *left,*right;
    TreeNode(char x): val(x), left(nullptr), right(nullptr) {};
};
class Binary_Tree{
private:
    TreeNode *T;
    int DFS_Order(TreeNode *root)
    {
        if(root==nullptr){
            return 0;
        }
        int left_Maxdepth = DFS_Order(root->left);
        int right_Maxdepth = DFS_Order(root->right);
        int MAX = max(left_Maxdepth,right_Maxdepth);
        return MAX+1;
    }
public:
    Binary_Tree(TreeNode *root){
        T=root;
    };
    int DFS_Order(){
        return DFS_Order(T);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Binary_Tree tree(root);
    cout<<tree.DFS_Order()<<endl;
    return 0;
}
