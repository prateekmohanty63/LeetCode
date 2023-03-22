#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
   
   void bfs(TreeNode *root,vector<vector<int>>&res)
   {
       queue<TreeNode*>q;
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
           res.push_back(vec);
       }
    
   }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>res;

        if(!root)return res;
         
         bfs(root,res);

        reverse(res.begin(),res.end());

        return res;
    }
};

int main()
{
    
    return 0;
}