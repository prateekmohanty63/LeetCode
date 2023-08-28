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

 /// approach-1
 /// test case not passing
class Solution {
public:
    int sum=0;
    int max_depth=0;
    int count=0;

    void depth(TreeNode *root){
        if(!root)
            return ;

        count++;

        if(!root->left && !root->right){
            if(count>max_depth)
                max_depth=count;
            count=0;

            return ;
        }

        if(root->left){
            depth(root->left);
        }
        if(root->right){
            depth(root->right);
        }
    }

    void res(TreeNode *root){

        if(!root)
            return ;

        count++;
        if(!root->left && !root->right){

            if(count==max_depth)
                sum+=root->val;

            cout<<sum<<" ";
            count=0;
            return ;
        }
        if(root->left){
            res(root->left);
        }
        if(root->right){
            res(root->right);
        }
    }
    int deepestLeavesSum(TreeNode* root) {

        depth(root);

        res(root);

        return sum;

    }
};


/// approach 2
/// working


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

    void deepest_leave(TreeNode *root,int &max_depth,int &ans,int h){

        if(!root)
            return ;

        if(max_depth<h)
            max_depth=h,ans=0;

        if(!root->left && !root->right && h==max_depth){
            ans+=root->val;
        }
        deepest_leave(root->left,max_depth,ans,h+1);
        deepest_leave(root->right,max_depth,ans,h+1);
    }
    int deepestLeavesSum(TreeNode* root) {

        if(!root)
            return 0;

        int max=0,an=0,height;

        deepest_leave(root,max,an,0);

        return an;
    }
};
