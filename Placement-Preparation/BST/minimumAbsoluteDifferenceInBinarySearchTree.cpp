#include<iostream>
#include<vector>
#include<climits>
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
   
   void inOrder(TreeNode *root,vector<int>&vec)
   {
       // base case
       if(!root)return ;
       
       inOrder(root->left,vec);
       vec.push_back(root->val);
       inOrder(root->right,vec);
   }

    int getMinimumDifference(TreeNode* root) {
        
        vector<int>vec;

        inOrder(root,vec);

        int minDiff=INT_MAX;

        for(int i=0;i<vec.size()-1;i++)
        {
            minDiff=min(minDiff,vec[i+1]-vec[i]);
        }
        return minDiff;
    }
};

int main()
{
    
    return 0;
}