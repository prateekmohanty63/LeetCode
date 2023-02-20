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
    
    int good(TreeNode *root,int maxVal)
    {
        if(!root)return 0;

       

       // if the cuurent value of the node is less than the current max return 1
        if(root->val>=maxVal){
            maxVal=max(root->val,maxVal);
            return 1+good(root->left,maxVal)+good(root->right,maxVal);
        }
        else{
            return good(root->left,maxVal)+good(root->right,maxVal);
        }

    
      
    }
    
    int goodNodes(TreeNode* root) {
        
        if(!root)return 0;

        int res=good(root,root->val);

        return res;
    }
};

int main()
{
    
    return 0;
}