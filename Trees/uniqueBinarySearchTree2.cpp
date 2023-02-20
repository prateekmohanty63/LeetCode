#include<iostream>
#include<vector>
using namespace std;

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
   
   vector<TreeNode*>helper(int start,int end)
   {
       // base case

       if(start>end)
       {
           vector<TreeNode*>base;
           base.push_back(NULL);
           return base;
       }
      vector<TreeNode*>res;
       for(int i=start;i<=end;i++)
       {
           vector<TreeNode*>left=helper(start,i-1);
           vector<TreeNode*>right=helper(i+1,end);

           for(TreeNode *l:left)
           {
               for(TreeNode *r:right)
               {
                   TreeNode *root=new TreeNode(i);
                   root->left=l;
                   root->right=r;
                   res.push_back(root);
               }
           }
       }
       return res;
   }


    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*>res;

        if(n==1)
        {
            TreeNode *root=new TreeNode(1);
            res.push_back(root);
            return res;
        }
      
      return helper(1,n);
        


    }
};

int main()
{
    
    return 0;
}