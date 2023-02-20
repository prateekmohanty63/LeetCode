#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Beats 91.60%: Time complexity
// Beats 69.23%: Space complexity


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    
    bool hasPath(TreeNode *root, vector<TreeNode *>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root);   
     
    // if it is the required node
    // return true
    if (root->val== x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;           
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode *>path1,path2;

        hasPath(root,path1,p->val);
        hasPath(root,path2,q->val);

        for(auto it:path1)cout<<it->val<<" ";

        cout<<endl;

        for(auto it:path2)cout<<it->val<<" ";

       unordered_map<int,TreeNode *>mp;

   
           for(auto it:path1)mp[it->val]=it;

           for(int i=path2.size()-1;i>=0;i--)
           {
               if(mp.find(path2[i]->val)!=mp.end())return mp[path2[i]->val];
           }
    
        return NULL;
    }
};

int main()
{
    
    return 0;
}