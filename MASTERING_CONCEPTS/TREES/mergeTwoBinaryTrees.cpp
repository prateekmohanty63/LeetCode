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
   
   void merge(TreeNode *root1,TreeNode *root2)
   {
       // base case
       
       //if(!root1 && !root2)return ;

      if(!root1 || !root2)return ;

       if(root1->left!=NULL && root2->left!=NULL)
       {
           root1->left->val+=root2->left->val;
       }
       if(root1->right!=NULL && root2->right!=NULL)
       {
           root1->right->val+=root2->right->val;
       }
        
        // left sub-Tree
       if(!root1->left && root2->left!=NULL)
       {
           TreeNode *temp=new TreeNode(root2->left->val);
           root1->left=temp;

            // root1->left=root2->left;
       }

       // right sub-Tree

       if(!root1->right && root2->right!=NULL)
       {
           TreeNode *temp=new TreeNode(root2->right->val);
           root1->right=temp;

          // root1->right=root2->right;
       }

       merge(root1->left,root2->left);
       merge(root1->right,root2->right);
       
   }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(!root1)return root2;

        if(!root2)return root1;

        root1->val+=root2->val;
         merge(root1,root2);

         return root1;
    }
};

int main()
{
    
    return 0;
}