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
 
 // T(N)=O(N^2)
 // S(N)=O(h)  
 
class Solution {
public:
    int height(TreeNode* root)
    {
        // base case
        if(!root)return 0;

        int left=height(root->left);
        int right=height(root->right);

        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
         // base case
         if(!root)return true;

         int leftDepth=height(root->left);
         int rightDepth=height(root->right);

         if(abs(leftDepth-rightDepth)>1)return false;

         return isBalanced(root->left) && isBalanced(root->right);

    }
};

int main()
{
    
    return 0;
}