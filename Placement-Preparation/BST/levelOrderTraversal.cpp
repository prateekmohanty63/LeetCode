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
   
   vector<vector<int>>res;

   void levelOrderTraversal(TreeNode *root)
   {
       queue<TreeNode*>q;
       q.push(root);

       if(!root)return ;

       while(!q.empty())
       {
           vector<int>vec;

            int size=q.size();

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

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        levelOrderTraversal(root);

        return res;
    }
};

int main()
{
    
    return 0;
}