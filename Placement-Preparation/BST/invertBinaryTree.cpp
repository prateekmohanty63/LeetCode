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
  
  void invert(TreeNode *root)
  {
      // base case
      if(!root)return ;

      swap(root->left,root->right);

      invert(root->left);
      invert(root->right);
  }

    TreeNode* invertTree(TreeNode* root) {
        
        invert(root);

        return root;
    }
};

int main()
{
    
    return 0;
}