#include<iostream>
using namespace std;

// better code

class Solution {
public:

   bool ans=true;

   int height(TreeNode *root)
   {
       if(!root)return 0;

       int leftDepth=height(root->left);
       int rightDepth=height(root->right);

     // if at any point we find the height difference to exceed 1 , we make the answer as false
       if(abs(leftDepth-rightDepth)>1)ans=false;

       if(leftDepth>rightDepth)return 1+leftDepth;

      else return 1+rightDepth;
       
   }

  

    bool isBalanced(TreeNode* root) {
        
        height(root);
       return ans;
    }
};


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