#include<iostream>
#include<vector>
#include<unordered_map>
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
  TreeNode *buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&mp)
  {
      // base case
      if(preStart>preEnd || inStart>inEnd)return NULL;

      TreeNode* root=new TreeNode(preorder[preStart]);

      int ind=mp[preorder[preStart]];
      int noEle=ind-inStart;

      root->left=buildTree(preorder,preStart+1,preStart+noEle,inorder,inStart,ind-1,mp);
      root->right=buildTree(preorder,preStart+noEle+1,preEnd,inorder,ind+1,inEnd,mp);

      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>mp;

        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }

        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size(),mp);
    }
};

int main()
{
    
    return 0;
}