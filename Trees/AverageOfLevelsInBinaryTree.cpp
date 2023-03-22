#include<iostream>
#include<queue>
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
   
   void bfs(TreeNode *root,vector<vector<int>>&levels)
   {
       queue<TreeNode*>q;
       q.push(root);


       while(!q.empty())
       {
           int size=q.size();
           vector<int>level;

           for(int i=0;i<size;i++)
           {
               TreeNode *front=q.front();
               q.pop();
               level.push_back(front->val);

               if(front->left)
               q.push(front->left);

               if(front->right)
               q.push(front->right);
           }
           levels.push_back(level);
            
       }
       
   }

    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<vector<int>>lev;

        vector<double>res;

        bfs(root,lev);

        for(int i=0;i<lev.size();i++)
        {
            double sum=0;

            for(int j=0;j<lev[i].size();j++)
            {
                sum+=lev[i][j];
            }

            sum/=lev[i].size();
            res.push_back(sum);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}