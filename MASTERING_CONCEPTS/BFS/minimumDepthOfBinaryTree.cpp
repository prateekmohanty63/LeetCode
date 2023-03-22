#include<iostream>
using namespace std;



//  Definition for a binary tree node.
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
   
   int depth(TreeNode *root)
   {
       // base case

       if(!root)return 100001;

       if(!root->left && !root->right)return 1;

       return min(1+depth(root->left),1+depth(root->right));
   }

    int minDepth(TreeNode* root) {
        
        if(!root)return 0;

        if(!root->left && !root->right)return 1;

        int res=min(depth(root->left),depth(root->right));

        return res+1;

    }
};

int main()
{
    
    return 0;
}