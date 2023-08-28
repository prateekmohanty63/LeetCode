#include<iostream>
#include<vector>

using namespace std;

  //Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>res;
        
        if(!root)return res;
        
        queue<TreeNode*>queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            int size=queue.size();
            vector<int>level;
            
            for(int i=0;i<size;i++)
            {
                TreeNode *front=queue.front();
                queue.pop();
                
                if(front->left)queue.push(front->left);
                if(front->right)queue.push(front->right);
                level.push_back(front->val);
            }
            
          res.push_back(level);  
        }
        return res;
    }
};

int main()
{
    
    return 0;
}