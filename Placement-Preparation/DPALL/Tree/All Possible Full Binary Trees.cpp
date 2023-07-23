#include<iostream>
#include<vector>
#include<map>
using namespace std;


// T(N)=O(2^n)

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
   vector<TreeNode*>solve(int n,map<int,vector<TreeNode*>>&dp)
   {
       // base case
       if(n==0)
       {
           return {};
       }

       if(n==1)
       {
           TreeNode* root=new TreeNode(0);
           return {root};
       }

       if(dp.find(n)!=dp.end())return dp[n];

       vector<TreeNode*>res;

       for(int i=0;i<n-1;i++)
       {
           // finding all possible combinations of number of nodes
           // in left and right sub-trees

           // comibations eg: leftTree=1 node , rightTreeNode=(7-1-1)=5 nodes
           vector<TreeNode*>leftTrees=solve(i,dp);
           vector<TreeNode*>rightTrees=solve(n-i-1,dp);

           for(auto it:leftTrees)
           {
               for(auto itr:rightTrees)
               {
                   TreeNode* node=new TreeNode(0,it,itr);
                   res.push_back(node);
               }
           }
       }
       return dp[n]=res;
   }
    vector<TreeNode*> allPossibleFBT(int n) {
        
        map<int,vector<TreeNode*>>dp;

        if(n%2==0)return {};
        vector<TreeNode*>res=solve(n,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}