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
       if(!root)return 0;

       int leftDepth=height(root->left);
       int rightDepth=height(root->right);

       if(leftDepth>rightDepth)return 1+leftDepth;

      else return 1+rightDepth;
       
   }

   bool isBal(TreeNode *root)
   {
       if(!root)return true;

       int leftHeight=height(root->left);
       int rightHeight=height(root->right);

      if(abs(leftHeight-rightHeight)>1)return false;

      return isBal(root->left) && isBal(root->right);
   }

    bool isBalanced(TreeNode* root) {
        
        if(!root)return true;

        cout<<height(root->left);
        cout<<" "<<height(root->right); 
        return isBal(root);
    }
};

int main()
{
    
    return 0;
}