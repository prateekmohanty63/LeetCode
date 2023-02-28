#include<iostream>
#include<vector>
#include<unordered_map>
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


   string sameTree(TreeNode *root,unordered_map<string,vector<TreeNode*>>&subTrees,vector<TreeNode *>&res)
   {
        // base case

        if(!root)return "null";

        string subStruct;

        subStruct=to_string(root->val)+"*"+sameTree(root->left,subTrees,res)+"*"+sameTree(root->right,subTrees,res);

        if(subTrees.find(subStruct)!=subTrees.end() && subTrees[subStruct].size()==1)
        {
               res.push_back(root);
        }
      
        subTrees[subStruct].push_back(root);
       

        return subStruct;


   }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,vector<TreeNode *>>subTrees;
        vector<TreeNode *>res;

        sameTree(root,subTrees,res);

        return res;
    }
};

int main()
{
    
    return 0;
}