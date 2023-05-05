#include<iostream>
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
   
   bool isSame(TreeNode *p,TreeNode *q)
   {
       // base case

       if(p==NULL && q!=NULL)return false;

       if(p!=NULL && q==NULL)return false;

       if(p==NULL && q==NULL)return true;

       if(p->val!=q->val)return false;

       return isSame(p->left,q->left) && isSame(p->right,q->right);
   }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return isSame(p,q);
    }
};

int main()
{
    
    return 0;
}