#include<iostream>
#include<climits>
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
   
   bool isBinary(TreeNode *root)
   {
       // base case

       if(!root)return true;

       int rootVal=root->val;
       int leftTreeVal;
       int rightTreeVal;

       if(root->left)leftTreeVal=root->left->val;
       else leftTreeVal=INT_MIN;
       
        if(root->right)rightTreeVal=root->right->val;
       else rightTreeVal=INT_MAX;

   //    if(leftTreeVal==rightTreeVal)return false;

       if(rootVal==leftTreeVal || rootVal==rightTreeVal)return false;
       


       if(leftTreeVal>rootVal || rightTreeVal<rootVal)return false;

       

       return isBinary(root->left) && isBinary(root->right);
   }

    bool isValidBST(TreeNode* root) {
        
        return isBinary(root);
    }
};

int main()
{
    
    return 0;
}