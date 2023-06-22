#include<iostream>
using namespace std;


 // Definition for a binary tree node.
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
    bool solve(TreeNode *root,int targetSum)
    {
        // base case
         if(root && !root->left && !root->right && (targetSum-root->val)==0)return true;
        if(!root)return false;


        return solve(root->left,targetSum-root->val) || solve(root->right,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum);
    }
};

int main()
{
    
    return 0;
}