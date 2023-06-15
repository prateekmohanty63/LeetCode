#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
    
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>>res;
        // queue for BFS
        queue<TreeNode*>q;

        // push the root into queue
        q.push(root);

        // BFS

        while(!q.empty())
        {
            int size=q.size();
            vector<int>vec;

            for(int i=0;i<size;i++)
            {
                TreeNode* fr=q.front();
                q.pop();
                vec.push_back(fr->val);

                if(fr->left)q.push(fr->left);

                if(fr->right)q.push(fr->right);

            }
            res.push_back(vec);
        }
        return res;
    }
    int maxLevelSum(TreeNode* root) {
        
        vector<vector<int>>res=levelOrder(root);

        int minLevel=-1;
        int maxSum=INT_MIN;

        for(int i=0;i<res.size();i++)
        {
            int sum=0;
            for(int j=0;j<res[i].size();j++){
                sum+=res[i][j];
            }

            if(sum>maxSum){
                maxSum=sum;
                minLevel=i+1;
            }

        }
        return minLevel;
    }
};

int main()
{
    
    return 0;
}