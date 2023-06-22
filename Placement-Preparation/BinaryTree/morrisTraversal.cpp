#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Inorder
vector<int> getInorder(TreeNode *root)
{
    vector<int>inorder;

    TreeNode *cur=root;

    while(cur!=NULL)
    {
        if(cur->left==NULL){
            // print
            inorder.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode *prev=cur->left;

            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }

            if(prev->right==NULL)
            {
                // create the thread
                prev->right=cur;
                cur=cur->left;
            }
            else{
                // thread already exists
                prev->right=NULL;
                inorder.push_back(cur->val);
                cur=cur->right;
            }
        }
    }
    return inorder;
}


// preorder

vector<int> getPreorder(TreeNode *root)
{
    vector<int>preorder;

    TreeNode *cur=root;

    while(cur!=NULL)
    {
        if(cur->left==NULL){
            // print
            preorder.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode *prev=cur->left;

            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }

            if(prev->right==NULL)
            {
                // create the thread
                prev->right=cur;
                preorder.push_back(cur->val);
                cur=cur->left;
            }
            else{
                // thread already exists
                prev->right=NULL;
                cur=cur->right;
            }
        }
    }
    return preorder;
}

int main()
{
    
    return 0;
}