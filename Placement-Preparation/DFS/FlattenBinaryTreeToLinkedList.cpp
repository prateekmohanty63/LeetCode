#include<iostream>
using namespace std;

 // unique approach (check video once)


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
    TreeNode *prev=NULL;
    void flatten(TreeNode* root) {
        
        if(!root)return ;

        flatten(root->right);
        flatten(root->left);
        
        root->left=NULL;
        root->right=prev;
        prev=root;

    }
};

int main()
{
    
    return 0;
}