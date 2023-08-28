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

 /// first approach (test cases failing)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root==NULL)
            return NULL;

        if(root->left==NULL && root->right==NULL && root!=NULL)
            return root;

        TreeNode *lchild=NULL;
        TreeNode *rchild=NULL;

        stack<TreeNode *>stk1;
        stack<TreeNode *>stk2;

        stk1.push(root->left);
        stk2.push(root->right);

        while(!stk1.empty() && !stk2.empty()){

            lchild=stk1.top();
            stk1.pop();
            rchild=stk2.top();
            stk2.pop();

            if(lchild!=NULL && rchild!=NULL){
            int a=lchild->val;
            lchild->val=rchild->val;
            rchild->val=a;
            }

            if(lchild->left!=NULL)
            stk1.push(lchild->left);

            if(lchild->right!=NULL)
            stk1.push(lchild->right);

            if(rchild->right!=NULL)
            stk2.push(rchild->right);

            if(rchild->left!=NULL)
            stk2.push(rchild->left);


        }
        return root;
    }
};



/// second approach
class Solution {
public:
    void recur(TreeNode *root){
        if(root==NULL)
            return ;

        invertTree(root->left);
        invertTree(root->right);



       TreeNode *temp=root->left;
       root->left=root->right;
        root->right=temp;


    }
    TreeNode* invertTree(TreeNode* root) {

        recur(root);
        return root;
    }
};


/// 3rd approach
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
    TreeNode* invertTree(TreeNode* root) {

        if(!root)
            return NULL;

        swap(root->right,root->left);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

};
