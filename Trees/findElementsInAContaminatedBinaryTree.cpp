#include<iostream>
#include<vector>
#include<unordered_map>
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
 
class FindElements {
public:
   TreeNode* res;
   unordered_map<int,bool>mp;


   void solve(TreeNode* root)
   {
       if(!root)return ;
       int currVal=root->val;

       if(root->left!=NULL)
       {
           root->left->val=2*currVal+1;
       }
       if(root->right!=NULL)
       {
           root->right->val=2*currVal+2;
       }
       solve(root->left);
       solve(root->right);
   }

   void inOrder(TreeNode* root)
   {
       if(!root)return ;
       inOrder(root->left);
       mp[root->val]=true;
       //cout<<root->val<<" ";
       inOrder(root->right);
   }
    FindElements(TreeNode* root) {
         
        TreeNode* head=root;
        head->val=0;

        solve(head);
        res=head;
        
        inOrder(res);

    }
    
    bool find(int target) {
        // for(auto it:mp)cout<<it.first<<" ";
        
        if(mp.find(target)!=mp.end())return true;
        return false;
      
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main()
{
    
    return 0;
}