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

// T(N)=O(N)
// S(N)=O(H)

class Solution {
public:
   unordered_map<TreeNode*,TreeNode*>parentPointers;
   

   void convertGraph(TreeNode*root)
   {
       // base case
       if(!root)return ;

       if(root->left!=NULL)
       {
           parentPointers[root->left]=root;
           convertGraph(root->left);
       }
       if(root->right!=NULL)
       {
           parentPointers[root->right]=root;
           convertGraph(root->right);
       }
   }
   TreeNode* targetNode(TreeNode* root,int &start)
   {
       // base case
       if(!root)return NULL;

       if(root->val==start)return root;

       TreeNode* left=targetNode(root->left,start);
       TreeNode* right=targetNode(root->right,start);

       if(left!=NULL)return left;
       if(right!=NULL)return right;

       return NULL;
   }
   int solve(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp)
   {
       // base case
       queue<pair<TreeNode*,int>>q;
       q.push({root,0});
       unordered_map<TreeNode*,bool>vis;
       vis[root]=true;

       int maxTime=INT_MIN;

       while(!q.empty())
       {
           TreeNode* curr=q.front().first;
           int currLevel=q.front().second;
           q.pop();
           maxTime=max(maxTime,currLevel);

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
           TreeNode* parent=parentPointers[curr];

           if(parent!=NULL && vis.find(parent)==vis.end())
           {
               vis[parent]=true;
               q.push({parent,currLevel+1});
           }

       }
       return maxTime;
   }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target=targetNode(root,start);
         convertGraph(root);
        //  for(auto it:parentPointers)cout<<it.first->val<<" "<<it.second->val<<endl;
        return solve(target,parentPointers);

    }
};

int main()
{
    
    return 0;
}