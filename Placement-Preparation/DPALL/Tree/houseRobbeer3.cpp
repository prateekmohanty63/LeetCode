#include<iostream>
#include<unordered_map>

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
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&dp)
    {
        // base case
        if(!root)return 0;

        if(dp.find(root)!=dp.end())return dp[root];

        // we have the opion of robing the current house 
        // or not robbing it
        int leftRight=0;
        int leftLeft=0;
        int rightLeft=0;
        int rightRight=0;

        
        if(root->left!=NULL)
        leftRight=solve(root->left->right,dp);

        if(root->left!=NULL)
        leftLeft=solve(root->left->left,dp);

        if(root->right)
        rightLeft=solve(root->right->left,dp);

        if(root->right)
        rightRight=solve(root->right->right,dp);

        int take=root->val+leftRight+leftLeft+rightLeft+rightRight;

        int notTake=solve(root->left,dp)+solve(root->right,dp);

        return dp[root]=max(take,notTake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        int res=solve(root,dp);

        return res;
    }
};
 
class Solution {
public:
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&dp)
    {
        // base case
        if(!root)return 0;

        if(dp.find(root)!=dp.end())return dp[root];

        // we have the opion of robing the current house 
        // or not robbing it
        int leftRight=0;
        int leftLeft=0;
        int rightLeft=0;
        int rightRight=0;

        
        if(root->left!=NULL)
        leftRight=solve(root->left->right,dp);

        if(root->left!=NULL)
        leftLeft=solve(root->left->left,dp);

        if(root->right)
        rightLeft=solve(root->right->left,dp);

        if(root->right)
        rightRight=solve(root->right->right,dp);

        int take=root->val+leftRight+leftLeft+rightLeft+rightRight;

        int notTake=solve(root->left,dp)+solve(root->right,dp);

        return max(take,notTake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        int res=solve(root,dp);

        return res;
    }
};

int main()
{

}