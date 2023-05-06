#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// T(N): O(N)

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
   
   void inOrderTraversal(TreeNode *root,vector<int>&vec)
   {
       // base case

       if(!root)return ;

       inOrderTraversal(root->left,vec);
       vec.push_back(root->val);

       inOrderTraversal(root->right,vec);

   }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>vec;
        inOrderTraversal(root,vec);

        return vec[k-1];
    }
};


// T(N):O(nlogn)


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
    
    void bst(TreeNode *root,vector<int>&vec)
    {
        // base case
        if(!root)return ;

        vec.push_back(root->val);

        bst(root->left,vec);
        bst(root->right,vec);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>vec;
        bst(root,vec);

        sort(vec.begin(),vec.end());

        return vec[k-1];
    }
};

int main()
{
    
    return 0;
}