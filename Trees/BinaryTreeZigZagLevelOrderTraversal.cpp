#include<iostream>
#include<vector>
#include<algorithm>

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
   
   int heightOfTree(TreeNode *root)
   {
       if(!root)return 0;

       int lh=heightOfTree(root->left);
       int rh=heightOfTree(root->right);

       if(lh>rh)return (lh+1);

       return rh+1;
   }

   void printCurrentLevel(TreeNode *root,int level, vector<int>&res)
   {

       if(!root)return ;

       if(level==1)
       {
           res.push_back(root->val);
       }
      else{
          printCurrentLevel(root->left,level-1,res);
          printCurrentLevel(root->right,level-1,res);
      }

   }

   vector<vector<int>> levelOrderTraversal(TreeNode *root)
   {
       int height=heightOfTree(root);

       vector<vector<int>>res;

       for(int i=1;i<=height;i++)
       {
           vector<int>vec;
           printCurrentLevel(root,i,vec);
           res.push_back(vec);
       }
       return res;
   }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>res;

        if(!root)return res;
        
        res=levelOrderTraversal(root);
     
        for(int i=0;i<res.size();i++)
        {
             if(i%2!=0)
             {
                 vector<int>vec=res[i];
                 reverse(vec.begin(),vec.end());
                 res[i]=vec;

             }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}