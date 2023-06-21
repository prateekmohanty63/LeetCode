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

    int diaTree(TreeNode *root)
    {
        if(!root)return 0;

        int lh=diaTree(root->left);
        int rh=diaTree(root->right);

        int dia=height(root->left)+height(root->right);

        return max(dia,max(lh,rh));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diaTree(root);
        
    }
};

int main()
{
    
    return 0;
}