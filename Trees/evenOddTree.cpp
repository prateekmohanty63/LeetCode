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
    
    bool evenOdd(TreeNode *root)
    {
        queue<TreeNode *>q;
        int level=0;
        vector<vector<int>>tree;
        

        q.push(root);

        while(!q.empty())
        {
             int levelLength=q.size();
             vector<int>lev;

             for(int i=0;i<levelLength;i++)
             {
                TreeNode *front=q.front();
                
                    q.pop();

                    if(front->left)
                    {
                        q.push(front->left);
                    }

                    if(front->right)
                    {
                        q.push(front->right);
                    }
                
                    lev.push_back(front->val);
             }
           
            tree.push_back(lev);
            
        }

        for(int i=0;i<tree.size();i++)
        {
            
            int m=tree[i].size();
            if(i%2==0)
            {
                for(int j=0;j<m-1;j++)
                {
                    if(tree[i][j]%2==0)return false;

                    if(tree[i][j]>=tree[i][j+1])return false;
                }

                if(tree[i][m-1]%2==0)return false;
            }
            else{
                for(int j=0;j<m-1;j++)
                {
                    if(tree[i][j]%2!=0)return false;

                    if(tree[i][j]<=tree[i][j+1])return false;
                }
                 if(tree[i][m-1]%2!=0)return false;
            }
        }
       return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        
       
        return evenOdd(root);
    }
};

int main()
{
    
    return 0;
}