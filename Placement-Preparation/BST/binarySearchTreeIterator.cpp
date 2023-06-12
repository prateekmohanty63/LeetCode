#include<iostream>
#include<vector>
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
 
 
class BSTIterator {
public:
    vector<int>vec;
    int k=0;
      void inOrder(TreeNode *root){
           if(!root)return ;

           inOrder(root->left);
           vec.push_back(root->val);
           inOrder(root->right);
       }

    BSTIterator(TreeNode* root) {
    
       inOrder(root);

       for(auto it:vec)cout<<it<<" ";
    }
    
    int next() {
        return vec[k++];
    }
    
    bool hasNext() {

        return (k<vec.size());

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    
    return 0;
}