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
   
   // REFER ADITYA VERMA DP ON TREES (VERY EASY SOLUTION)
    int maxSumTree(TreeNode *root,int &res)
    {
        // base case
        if(!root)return 0;
        
        // hypothesis
        int left=maxSumTree(root->left,res);
        int right=maxSumTree(root->right,res);

        // induction
        int temp=max(root->val,max(left,right)+root->val);
        // calculating the left subtree sum and rightsubtree sum
        int ans=max(temp,left+right+root->val);
        res=max(res,ans);
        
        return temp;
    }
   

    int maxPathSum(TreeNode* root) {
        
        if(!root)return 0;

        int ans=INT_MIN;

        maxSumTree(root,ans);

        return ans;
    }
};

int main()
{
    
    return 0;
}