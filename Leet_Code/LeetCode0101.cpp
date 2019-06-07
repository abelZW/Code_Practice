#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
三种情况：
1、左右都为空
2、左右一个有一个没有
3、左右有不对称
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( root == NULL ){
            return true;
        }
        
        return isEqual(root->left, root->right);            
    }
    bool isEqual(TreeNode* left, TreeNode* right)
    {//给定的两个节点已经是对应位置上的节点
        if( left == NULL && right == NULL )
        {//两个节点都是空
            return true;
        }
        if( left == NULL || right == NULL )
        {//有一个节点是空
            return false;
        }
        if( left->val != right->val )
        {//两个节点都存在，但是不相同
            return false;
        }
        
        return isEqual(left->left, right->right) && isEqual(left->right, right->left);       
    }
};
int main(void)
{
#if 1
    struct TreeNode root, n10, n11, n20, n21, n22, n23;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n20.val = 3;
    n21.val = 4;
    n22.val = 4;
    n23.val = 3;
    root.left = &n10;
    root.right = &n11;
    n10.left = &n20;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = &n23;
    n20.left = NULL;
    n20.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
    n23.left = NULL;
    n23.right = NULL;
#else
    struct TreeNode root, n10, n11, n21, n22;
    root.val = 1;
    n10.val = 2;
    n11.val = 2;
    n21.val = 3;
    n22.val = 4;
    root.left = &n10;
    root.right = &n11;
    n10.left = NULL;
    n10.right = &n21;
    n11.left = &n22;
    n11.right = NULL;
    n21.left = NULL;
    n21.right = NULL;
    n22.left = NULL;
    n22.right = NULL;
#endif

    printf("%s\n", Solution::isSymmetric(&root) ? "true" : "false");
    return 0;
}