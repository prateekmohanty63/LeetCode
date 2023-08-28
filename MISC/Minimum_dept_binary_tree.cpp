
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

 /// 1st Approch
 /// Runtime: 252 ms, faster than 35.05% of C++ online submissions for Minimum Depth of Binary Tree.
/// Memory Usage: 146.6 MB, less than 5.40% of C++ online submissions for Minimum Depth of Binary Tree.


class Solution {
public:
    int Answer(TreeNode *root)
    {
        if(root->left==NULL && root->right==NULL)
            return 1;
        int lh=0,rh=0;
        if(root->left!=NULL){
            lh=minDepth(root->left);
        }

        if(root->right){
            rh=minDepth(root->right);
        }

        if(lh==0)
            return rh+1;
        if(rh==0)
            return lh+1;

        return min(lh,rh)+1;

    }

    int minDepth(TreeNode* root) {

        if(!root)
            return NULL;

        int res=Answer(root);
        return res;
    }
};

/// 2nd approch

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

 /// Runtime: 228 ms, faster than 68.00% of C++ online submissions for Minimum Depth of Binary Tree.
/// Memory Usage: 144.7 MB, less than 43.61% of C++ online submissions for Minimum Depth of Binary Tree.
/// recursion using the given function

class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root==NULL)
            return 0;

        int lh=minDepth(root->left);
        int rh=minDepth(root->right);

        if(lh==0)
            return rh+1;
        if(rh==0)
            return lh+1;

        return min(lh,rh)+1;
    }
};

/// 3rd approch
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root){
            if(!root->left && !root->right)
                return 1;

            if(!root->left)
                return 1+minDepth(root->right);

            if(!root->right)
                return 1+minDepth(root->left);
            else
                return min(minDepth(root->left),minDepth(root->right))+1;
        }
        return 0;
    }
};
