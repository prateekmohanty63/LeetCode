#include<iostream>
#include<vector>
#include<climits>
using namespace std;


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
   
   int count=0;

   void countGood(TreeNode *root,int maxim)
   {
       if(!root)return ;

       if(root->val>=maxim)count++;

       maxim=max(maxim,root->val);

       countGood(root->left,maxim);
       countGood(root->right,maxim);
   }

    int goodNodes(TreeNode* root) {
        
        int maxim=INT_MIN;
        countGood(root,maxim);

        return count;
    }
};


// T(N):O(N^2)
// space complexity: O(N)

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
   
   bool hasPath(TreeNode *root,TreeNode *target,vector<int>&path)
   {
        // base case

        if(!root)return false;

        path.push_back(root->val);


        if(root==target)return true;

        
        if(hasPath(root->left,target,path) || hasPath(root->right,target,path))
        {
            return true;
        }
        
      path.pop_back();

      return false;

   }

   vector<vector<int>>paths;

   void findPath(TreeNode *root,TreeNode *tempRoot)
   {
       // base case
       if(!tempRoot)return ;
       vector<int>vec;

       if(hasPath(root,tempRoot,vec))
       {
           paths.push_back(vec);
       }

       findPath(root,tempRoot->left);
       findPath(root,tempRoot->right);
   }
    int goodNodes(TreeNode* root) {
        
        int res=0;

        findPath(root,root);

        for(int i=0;i<paths.size();i++)
        {
            if(paths[i].size()==1)
            {
                res++;
                continue;
            }
            
            int ele=paths[i][paths[i].size()-1];
            int flag=0;
            for(int j=0;j<paths[i].size()-1;j++)
            {
                if(paths[i][j]>ele)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)res++;
            // for(int j=0;j<paths[i].size();j++)
            // {
            //     cout<<paths[i][j]<<" ";
            // }
            cout<<endl;
        }

        return res;

    }
};

int main()
{
    
    return 0;
}