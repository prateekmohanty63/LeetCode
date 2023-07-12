#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// approach-1 (failing for some cases || logic wrong)


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
   vector<int>res;
   int targetDist;
   unordered_map<int,vector<int>>mp;

   void rootTarget(TreeNode *root,TreeNode *target,int dist)
   {
       // base case
       if(!root)return ;

       if(root==target)
       {
           targetDist=dist;
           return ;
       }

       rootTarget(root->left,target,dist+1);
       rootTarget(root->right,target,dist+1);
   }

   void allDist(TreeNode* root,int level)
   {
       // base case
       if(!root)return ;

       mp[level].push_back(root->val);

       allDist(root->left,level+1);
       allDist(root->right,level+1);
   }

   void solve(TreeNode* root,int level,int &k)
   {
       // base case
       if(!root)return ;
       if(level==k)res.push_back(root->val);

       solve(root->left,level+1,k);
       solve(root->right,level+1,k);
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(target,0,k);
        rootTarget(root,target,0);
        allDist(root,0);
        
        for(auto it:mp)
        {
            if(it.first+targetDist==k)
            {
                vector<int>vec=it.second;
               
                for(auto itr:vec){
                 if(itr!=target->val)
                res.push_back(itr);
                }
            }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}