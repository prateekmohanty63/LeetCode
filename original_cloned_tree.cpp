/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/// approach -1
/// Runtime: 960 ms, faster than 8.78% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
/// Memory Usage: 164 MB, less than 60.07% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.

class Solution {
public:
    TreeNode *ans;
    void res(TreeNode *original,TreeNode *cloned,TreeNode *target){

        if(!original) return  ;

        if(original==target){
            ans=cloned;
        }

        if(!original->left && !original->right){

            return ;
        }

        if(original->left)
        {
            res(original->left,cloned->left,target);
        }
        if(original->right){
            res(original->right,cloned->right,target);
        };
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

       res(original,cloned,target);

        return ans;
    }
};


/// approach-2


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        if(!original) return NULL;

        if(original==target) return cloned;

        TreeNode *l=getTargetCopy(original->left,cloned->left,target);
        TreeNode *r=getTargetCopy(original->right,cloned->right,target);

        return (l!=NULL) ? l:r;
    }
};
