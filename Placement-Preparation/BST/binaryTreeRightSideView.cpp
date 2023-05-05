#include<iostream>
#include<vector>
#include<queue>
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
   
   vector<vector<int>>level;

   void rightView(TreeNode *root)
   {
       // base case

      queue<TreeNode *>q;
      q.push(root);

      while(!q.empty())
      {
          int size=q.size();
           vector<int>vec;
          for(int i=0;i<size;i++)
          {
              TreeNode *front=q.front();
              q.pop();

              vec.push_back(front->val);

              if(front->left)q.push(front->left);

              if(front->right)q.push(front->right);
          }
          level.push_back(vec);
      }
      

   }

    vector<int> rightSideView(TreeNode* root) {
        
       vector<int>res;
        if(!root)return {};

        rightView(root);

       for(int i=0;i<level.size();i++)
       {
           vector<int>vec=level[i];
           res.push_back(vec[vec.size()-1]);
       }

        return res;
    }
};

int main()
{
    
    return 0;
}