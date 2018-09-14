/*
 Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 
 You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 Input:
 Tree 1                     Tree 2
  1                          2
 / \                        / \
3   2                      1   3
   /                        \   \
  5                          4   7
 Output:
 Merged tree:
    3
   / \
  4   5
 / \   \
5   4   7
*/
#include <iostream>
using namespace std;

//  node body & initialization
struct TreeNode{
    
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};
/*
    Pt.1:
        If either root is empty, return the other root
    Pt.2:
        add t2 onto t1 then,
        recursively traverse t1 & t2 on the left
        recursively traverse t1 & t2 on the right
    Pt.3:
        when finished return the head to t1
*/
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//  Pt1
    if (!t2)
        return t1;
    if (!t1)
        return t2;
//  Pt.2
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
//  Pt.3
    return t1;
}

void insert(TreeNode *& tree, int item) {
    if (tree == nullptr) {
        tree = new TreeNode(item);
    } else if (item < tree->val) {
        insert(tree->left, item);
    } else {
        insert(tree->right, item);
    }

}
//  prints tree in acending order
void print_inorder(TreeNode *p) {
    if (p != NULL) {
        print_inorder(p->left);
        cout << p->val << endl;
        print_inorder(p->right);
    }
}

int main() {
    TreeNode *root(nullptr);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 5);
    
    TreeNode *otherNode(nullptr);
    insert(otherNode, 2);
    insert(otherNode, 72);
    insert(otherNode, 21);
    
    root = mergeTrees(root, otherNode);
    
    print_inorder(root);
    

    
    cout << "End\n";
    return 0;
}
