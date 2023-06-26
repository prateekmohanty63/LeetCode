#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;


// T(N)=O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
   // here we are indexing the nodes
    int bfs(TreeNode *root)
    {
        // queue
        if(!root)return 0;
        
       queue<pair<TreeNode *,long long>>q;
       
       int ans=0;
       q.push({root,0});
      

       while(!q.empty())
       {
           int size=q.size();
           long long minim=(long long)q.front().second;
          int first,last;
           
           for(int i=0;i<size;i++)
           {
               int curr_id=(long long)q.front().second-minim;
               TreeNode* node=q.front().first;
               q.pop();

               if(i==0)first=curr_id;
               if(i==size-1)last=curr_id;

               if(node->left)q.push({node->left,(long long)2*curr_id+1});
               if(node->right)q.push({node->right,(long long)2*curr_id+2});

           }
          ans=max(ans,last-first+1);
       }

       return ans;
        
    }
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;
         
         int res=bfs(root);

         return res;
        
        
    }
};


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


// T(N)=O(log2(N)*(2^log2(N)))
 
class Solution {
public:
    void dfs(TreeNode *root,int currLevel,int maxLevel)
    {
        // base case
        if(!root)return ;

        if(currLevel==maxLevel)return ;

        if(root && !root->left)root->left=new TreeNode(-101);
        if(root && !root->right)root->right=new TreeNode(-101);

        dfs(root->left,currLevel+1,maxLevel);
        dfs(root->right,currLevel+1,maxLevel);
    }
    int height(TreeNode *root)
    {
        if(!root)return 0;

        int lheight=height(root->left);
        int rheight=height(root->right);

        if(lheight>rheight)return 1+lheight;

        return 1+rheight;
    }

    vector<vector<int>>bfs(TreeNode *root)
    {
        // queue
        queue<TreeNode*>q;
        
        vector<vector<int>>res;

        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            vector<int>vec;
            for(int i=0;i<size;i++)
            {
                TreeNode* tp=q.front();
                q.pop();
                vec.push_back(tp->val);

                if(tp->left)q.push(tp->left);

                if(tp->right)q.push(tp->right);
            }
            res.push_back(vec);
        }
        return res;
    }
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;

        int level=height(root);     // O(N)
        dfs(root,1,level);

        int maxWidth=INT_MIN;

        vector<vector<int>>vec=bfs(root);   // O(N)

        for(int i=0;i<vec.size();i++)         // O(log2(N))
        {
            vector<int>v=vec[i];
            int start=0;
            int end=v.size()-1;

            while(start<v.size() && v[start]==-101)start++; // O(2^log2(n))
            while(end>=0 && v[end]==-101)end--;

            maxWidth=max(maxWidth,end-start+1);
            
        }

        //cout<<level;

        return maxWidth;
    }
};

int main()
{
    
    return 0;
}