#include<iostream>
#include<stack>

using namespace std;
 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *lchild=NULL;
        TreeNode *rchild=NULL;
        
        if(root==NULL)
            return true;
        
        stack<TreeNode *>stk1;
        stack<TreeNode *>stk2;
        
        stk1.push(root->left);
        stk2.push(root->right);
        
        
        while(!stk1.empty() && !stk2.empty())
        {
            lchild=stk1.top();
            stk1.pop();
            rchild=stk2.top();
            stk2.pop();
            
            if(!lchild && !rchild)
                continue;
            else if(!lchild || !rchild)
                return false;
            if(lchild->val!=rchild->val)
                return false;
            
            stk1.push(lchild->left);
            stk1.push(lchild->right);
            
             stk2.push(rchild->right);
            stk2.push(rchild->left);
           
            
        }
        return true;
    }
};