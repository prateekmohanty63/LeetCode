#include<iostream>
using namespace std;


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
    


    void swapNode(TreeNode *root)
    {
        if(!root)return ;

        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;

        swapNode(root->left);
        swapNode(root->right);
    }
  
    TreeNode* invertTree(TreeNode* root) {
         
         if(!root)return NULL;

      
        swapNode(root);
         return root;
    }
};

int main()
{
    
    return 0;
}