#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
  vector<vector<int>> solve(TreeNode *root)
  {
      vector<vector<int>>res;

      if(!root)return res;
      // queue 
      queue<pair<TreeNode*,pair<int,int>>>q;

      // push root to queue
      q.push({root,{0,0}});

     map<int,map<int,multiset<int>>>mp;

      while(!q.empty())
      {
          auto x=q.front();
          q.pop();

          TreeNode* node=x.first;
          int val=x.first->val;
          int line=x.second.second;
          int v=x.second.first;
         
         mp[v][line].insert(val);

          if(node->left)
          {
              q.push({node->left,{v-1,line+1}});
          }
          if(node->right)
          {
              q.push({node->right,{v+1,line+1}});
          }
           
      }
      for(auto i:mp){
          vector<int>v;
          for(auto j:i.second)
          {
              for(auto g:j.second)
              v.push_back(g);
          }
          res.push_back(v);
      }

      return res;

  }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res=solve(root);

        return res;
    }
};

int main()
{
    
    return 0;
}