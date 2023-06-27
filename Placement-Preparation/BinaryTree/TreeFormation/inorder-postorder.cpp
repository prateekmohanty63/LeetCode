#include<iostream>
#include<unordered_map>
#include<vector>
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
    TreeNode *makeTree(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int pstart,int pend,unordered_map<int,int>&mp)
    {
        // base case
        if(inStart>inEnd || pstart>pend)return NULL;
        
        int data=postorder[pend];
        int ind=mp[data];
        int noEle=ind-inStart;

        TreeNode* root=new TreeNode(data); 
        root->left=makeTree(inorder,inStart,ind-1,postorder,pstart,pstart+noEle-1,mp);
        root->right=makeTree(inorder,ind+1,inEnd,postorder,pstart+noEle,pend-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int>mp;
         
         for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;


        return makeTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};

int main()
{
    
    return 0;
}