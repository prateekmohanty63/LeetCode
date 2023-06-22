#include<iostream>
#include<vector>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

// T(N)=O(N^2)
// S(N)=O(N^2)
class Solution {
public:
    vector<vector<TreeNode*>>res;

    void dfs(TreeNode *root,vector<TreeNode*>&vec)
    {
          // base case
          if(!root)return ;
          vec.push_back(root);
          dfs(root->left,vec);
          dfs(root->right,vec);
    }
    
    void dfsNode(TreeNode *root)
    {
        if(!root)return ;

        vector<TreeNode*>vec;
        dfs(root,vec);
        res.push_back(vec);

        dfsNode(root->left);
        dfsNode(root->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        dfsNode(root);

        for(int i=res.size()-1;i>=0;i--)
        {
            int count=0;
            for(int j=0;j<res[i].size();j++)
            {
               if(res[i][j]==p)count++;
               if(res[i][j]==q)count++;
            }
            if(count==2)return res[i][0];
            // cout<<endl;
        }

        return NULL;
    }
};

int main()
{
    
    return 0;
}