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

// T(N)=O(N)
// S(N)=O(H) = O(N) (skewed tree)
  pair<bool,int> isBalancedFast(TreeNode* root)
    {
        // base case
        if(!root)return {true,0};

        pair<bool,int>left=isBalancedFast(root->left);
        pair<bool,int>right=isBalancedFast(root->right);

        bool leftBalanced=left.first;
        bool rightBalanced=right.first;

        bool diff=abs(left.second-right.second)<=1; 

        pair<bool,int>ans;
        ans.first=leftBalanced && rightBalanced && diff;
        ans.second=max(left.second,right.second)+1;     // height = max(leftHeight,rightHeight)+1

        return ans;
    }
    bool isBalanced(TreeNode* root) {
         // base case
         if(!root)return true;
         return isBalancedFast(root).first;

    }
 
 // T(N)=O(N^2)
 // S(N)=O(h)  

class Solution {
public:
    int height(TreeNode* root)
    {
        // base case
        if(!root)return 0;

        int left=height(root->left);
        int right=height(root->right);

        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
         // base case
         if(!root)return true;

         int leftDepth=height(root->left);
         int rightDepth=height(root->right);

         if(abs(leftDepth-rightDepth)>1)return false;

         return isBalanced(root->left) && isBalanced(root->right);

    }
};

int main()
{
    
    return 0;
}