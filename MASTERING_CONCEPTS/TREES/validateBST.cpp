#include<iostream>
#include<climits>
#include<vector>
using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// solution-1

class Solution {
public:
   
   bool checkLeftSubTree(int &rootVal,TreeNode *root)
   {
       // base case

       if(!root)return true;

       int nodeVal=root->val;

       if(nodeVal>=rootVal)return false;

       return checkLeftSubTree(rootVal,root->left) && checkLeftSubTree(rootVal,root->right);
   }

   bool checkRightSubTree(int &rootVal,TreeNode *root)
   {
       // base case

       if(!root)return true;

       int nodeVal=root->val;

        if(nodeVal<=rootVal)return false;

       return checkRightSubTree(rootVal,root->left) && checkRightSubTree(rootVal,root->right);
   }

    bool isValidBST(TreeNode* root) {
        
        if(!root)return true;
        
        bool leftTree=true;
        bool rightTree=true;
       
       if(root->left)
        leftTree=checkLeftSubTree(root->val,root->left);
      
      if(root->right)
      rightTree=checkRightSubTree(root->val,root->right);

      if(!leftTree || !rightTree)return false;

      return isValidBST(root->left) && isValidBST(root->right);

    }
};


// solution-2
class Solution {
public:
    void inorder(TreeNode *root,vector<int>&vec1)
    {
        if(!root)return ;
        inorder(root->left,vec1);
        vec1.push_back(root->val);
        inorder(root->right,vec1);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int>vec1;
        
        inorder(root,vec1);
        
        for(int i=0;i<vec1.size();i++)
            cout<<vec1[i]<<" ";
        
        int n=vec1.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(vec1[i+1]<=vec1[i])return false;
        }
        
        return true;
    }
};



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
   
   bool isBinary(TreeNode *root)
   {
       // base case

       if(!root)return true;

       int rootVal=root->val;
       int leftTreeVal;
       int rightTreeVal;

       if(root->left)leftTreeVal=root->left->val;
       else leftTreeVal=INT_MIN;
       
        if(root->right)rightTreeVal=root->right->val;
       else rightTreeVal=INT_MAX;

   //    if(leftTreeVal==rightTreeVal)return false;

       if(rootVal==leftTreeVal || rootVal==rightTreeVal)return false;
       


       if(leftTreeVal>rootVal || rightTreeVal<rootVal)return false;

       

       return isBinary(root->left) && isBinary(root->right);
   }

    bool isValidBST(TreeNode* root) {
        
        return isBinary(root);
    }
};

int main()
{
    
    return 0;
}