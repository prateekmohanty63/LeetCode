
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
    int Height(TreeNode *temp1){

       if(temp1==NULL)
           return 0;

        int lh=Height(temp1->left);
        int rh=Height(temp1->right);

        if(lh>rh)
            return lh+1;
        return rh+1;
    }

public:
    bool isBalanced(TreeNode* root) {

        if(root==NULL)
            return true;

        int lh=Height(root->left);
        int rh=Height(root->right);

        if(abs(lh-rh)>1)
            return false;

        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;

        return true;
    }
};

class Solution {
    int Height(TreeNode *temp1){

       if(temp1==NULL)
           return 0;

        int lh=Height(temp1->left);
        int rh=Height(temp1->right);

        if(abs(lh-rh)>1)
            return -1;

        if(lh>rh)
            return lh+1;
        return rh+1;
    }

public:
    bool isBalanced(TreeNode* root) {

        if(root==NULL)
            return true;

        int lh=Height(root->left);
        int rh=Height(root->right);

        if(lh==-1 || rh==-1)
            return false;

        if(abs(lh-rh)>1)
            return false;

        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;

        return true;
    }
};



/// FASTER THAN 97 %

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
    int Height(TreeNode *temp1){

       if(temp1==NULL)
           return 0;


        int lh=Height(temp1->left);
        int rh=Height(temp1->right);

        if(abs(lh-rh)>1)
            return -1;

        if(lh>rh)
            return lh+1;
        return rh+1;
    }

public:
    bool isBalanced(TreeNode* root) {

        if(root==NULL)
            return true;

        if(root->left!=NULL)
        {
            if(!isBalanced(root->left))
                return false;
        }

        if(root->right!=NULL)
        {
            if(!isBalanced(root->right))
                return false;
        }

        int lh=Height(root->left);
        int rh=Height(root->right);

        if(lh==-1 || rh==-1)
            return false;

        if(abs(lh-rh)>1)
            return false;

        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;

        return true;
    }
};
