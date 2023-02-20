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
    long long sum=0;long long ans=0;
    long long totalTreeSum(TreeNode *root)
    {
        // base case
        if(!root)return 0;

        return totalTreeSum(root->left)+totalTreeSum(root->right)+root->val;

      
    }

    long long help2(TreeNode *root)
    {
        // base case

        if(!root)return 0;

        long long left=help2(root->left);
        long long right=help2(root->right);

         long long up=sum-left-right-root->val;

         long long op1=left*((long long)right+up+root->val);
         long long op2=right*((long long)left+up+root->val);
         long long op3=up*((long long)left+right+root->val);

         ans=max(ans,max(op1,max(op2,op3)));

         return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        
      // total sum of tree
       
        sum=totalTreeSum(root);
       // cout<<sum<<" ";

        help2(root);

        return ans%1000000007;


     
    }
};

int main()
{
    
    return 0;
}