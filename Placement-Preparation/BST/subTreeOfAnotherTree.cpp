#include<iostream>
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
    
    bool sameTree(TreeNode *root,TreeNode *subRoot)
    {
        // base case

        if(root==NULL && subRoot!=NULL)return false;

        if(root!=NULL && subRoot==NULL)return false;

        if(root==NULL && subRoot==NULL)return true;

        if(root->val!=subRoot->val)return false;

        return sameTree(root->left,subRoot->left) && sameTree(root->right,subRoot->right);
    }

    bool same(TreeNode *root,TreeNode *subRoot)
    {
        if(!root)return false;
        if(root->val==subRoot->val)
        {
            TreeNode *temp=subRoot;
            if(sameTree(root,temp)==true)return true;
        }

        return same(root->left,subRoot) || same(root->right,subRoot);
    }
  
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return same(root,subRoot);
    }
};

int main()
{
    
    return 0;
}