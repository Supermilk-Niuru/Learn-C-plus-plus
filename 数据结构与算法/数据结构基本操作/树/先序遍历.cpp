#include<iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {} 
};
class BinaryTree {
private:
    TreeNode* T;
    void presort(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " "; 
            presort(node->left);      
            presort(node->right);     
        }
    }
public:
    BinaryTree(TreeNode* root) {
        T = root;
    }
    void presort() {
        presort(T); 
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    BinaryTree tree(root);
    cout << "先序遍历结果为: ";
    tree.presort(); 
    return 0;
}
