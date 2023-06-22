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
    int height(TreeNode *root)
    {
        // base case
        if(!root)return 0;

        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfTree(TreeNode *root,int &res)
    {
        // base case
        if(!root)return 0;

        // hypothesis 
        int leftTree=diameterOfTree(root->left,res);
        int rightTree=diameterOfTree(root->right,res);

        // induction 
        int temp=max(leftTree,rightTree);    // value to be passed to parent node
        int ans=max(temp,height(root->left)+height(root->right));  // if current node is the answer
        res=max(res,ans);

        return temp;      // pass value to parent


    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int res=INT_MIN;
        diameterOfTree(root,res);

        return res;
    }
};

int main()
{
    
    return 0;
}