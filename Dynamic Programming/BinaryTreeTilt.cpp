#include<iostream>
using namespace std;




//Definition for a binary tree node.
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
     
     int subTreeSum(TreeNode* root)
     {
         if(!root)return 0;

          return root->val+subTreeSum(root->left)+subTreeSum(root->right);
     }

    void sum(TreeNode *root,int &res)
    {
        if(!root)return ;

        
        int leftSubTreeSum,rightSubTreeSum;

        if(root->left)
        leftSubTreeSum=subTreeSum(root->left);
        else leftSubTreeSum=0;

        if(root->right)
        rightSubTreeSum=subTreeSum(root->right);

        else rightSubTreeSum=0;
       
       res+=abs(leftSubTreeSum-rightSubTreeSum);

       sum(root->left,res);
       sum(root->right,res);

    }

    int findTilt(TreeNode* root) {
        
        int res=0;

        sum(root,res);
        
        cout<<res;

        return res;
    }
};

int main()
{
    
    return 0;
}