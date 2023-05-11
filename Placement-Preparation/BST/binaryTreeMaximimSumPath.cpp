#include<iostream>
#include<climits>
#include<algorithm>

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

    int maxim=INT_MIN;

    int maxSumTree(TreeNode *root)
    {
        // base case
        if(!root)return (-998152369);

        int a=0;
        int b=0;

        a=a+maxSumTree(root->left);
        b=b+maxSumTree(root->right);

        int leftSum=root->val+a;
        int rightSum=root->val+b;
        int uShaped=root->val+a+b;

        int kk=max({leftSum,rightSum,root->val});
        maxim=max({maxim,kk,uShaped});

        return kk;
    }
   

    int maxPathSum(TreeNode* root) {
        
        if(!root)return 0;

        maxSumTree(root);

        return maxim;
    }
};

int main()
{
    
    return 0;
}