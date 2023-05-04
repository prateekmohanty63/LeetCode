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
 

class Solution {
public:
   
   bool pathToTree(TreeNode *root,TreeNode* target,vector<TreeNode*>&vec)
   {
       // base case
       if(!root)return false;

       vec.push_back(root);

        if(root==target)return true;

       if(pathToTree(root->left,target,vec) || pathToTree(root->right,target,vec))
       {
           return true;
       }

       vec.pop_back();

       return false;
        
        
   }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*>vec,vec1;

        pathToTree(root,p,vec);
        pathToTree(root,q,vec1);

        for(auto it:vec)cout<<it->val<<" ";
        cout<<endl;

        for(auto it:vec1)cout<<it->val<<" ";

        int n=vec.size();
        int m=vec1.size();
        int ptr1,ptr2;

        if(n<m)
        {
           ptr1=n-1;
           ptr2=n-1;
        }
        else{
            ptr1=m-1;
            ptr2=m-1;
        }

        while(ptr1>=0 && ptr2>=0)
        {
            if(vec[ptr1]==vec1[ptr2])return vec[ptr1];

            ptr1--;
            ptr2--;
        }
        return NULL;
    }
};

int main()
{
    
    return 0;
}