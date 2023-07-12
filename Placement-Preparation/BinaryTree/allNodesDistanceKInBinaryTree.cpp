#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;



 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// Way to convert tree into un-directed tree or graph
// T(N)=O(N)
// S(N)=O(N)
 
class Solution {
public:
   unordered_map<TreeNode*,TreeNode*>parentPointers;
   unordered_map<TreeNode*,bool>vis;
   vector<int>res;

   void solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp,int &k)
   {   
       queue<pair<TreeNode*,int>>q;
       q.push({root,0});
       vis[root]=true;
       

       while(!q.empty())
       {
           TreeNode* curr=q.front().first;
           int currLevel=q.front().second;
           cout<<curr->val<<" "<<currLevel<<endl;
           q.pop();

           if(currLevel==k)res.push_back(curr->val);

           if(curr->left!=NULL && vis.find(curr->left)==vis.end())
           {
               vis[curr->left]=true;
               q.push({curr->left,currLevel+1});
           }
           if(curr->right!=NULL && vis.find(curr->right)==vis.end())
           {
               vis[curr->right]=true;
               q.push({curr->right,currLevel+1});
           }
           TreeNode* parent=mp[curr];
           if(parent!=NULL && vis.find(parent)==vis.end())
           {
               vis[parent]=true;
               q.push({parent,currLevel+1});
           }
       }
   }

   void inOrder(TreeNode *root)
   {
       // base case
       if(!root)return ;

       if(root->left){
       parentPointers[root->left]=root;
       inOrder(root->left);
       }

       if(root->right){
       parentPointers[root->right]=root;
       inOrder(root->right);
       }
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        inOrder(root);

       // for(auto it:parentPointers)cout<<it.first->val<<" "<<it.second->val<<endl;

        solve(target,parentPointers,k);

        return res;
    }
};


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