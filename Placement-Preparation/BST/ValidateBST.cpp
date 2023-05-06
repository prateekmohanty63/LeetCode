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
   
   bool checkLeft(TreeNode *root,int &target)
   {
       // base case

       if(!root)return true;

       if(target<=root->val)return false;

       return checkLeft(root->left,target) && checkLeft(root->right,target);
   }

   bool checkRight(TreeNode *root,int &target)
   {
       // base case

       if(!root)return true;

       if(target>=root->val)return false;

      
       return checkRight(root->left,target) && checkRight(root->right,target);
   }

    bool isValidBST(TreeNode* root) {
        
        // base case

        if(!root)return true;

        int target=root->val;

        bool leftSubTree,rightSubTree;

        if(root->left)
        leftSubTree=checkLeft(root->left,target);
        
        else leftSubTree=true;

        if(root->right)
        rightSubTree=checkRight(root->right,target);

        else rightSubTree=true;

        if(!leftSubTree || !rightSubTree)return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
};

int main()
{
    
    return 0;
}