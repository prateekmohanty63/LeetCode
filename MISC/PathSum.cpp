
/// Approach 1


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

 /// Runtime: 20 ms, faster than 15.39% of C++ online submissions for Path Sum.
/// Memory Usage: 21.1 MB, less than 92.85% of C++ online submissions for Path Sum.

class Solution {
public:

    void sumPath(TreeNode *root,vector<int>&vec1,int a){
        if(!root)
            return ;

         a+=root->val;
        if(!root->left && !root->right){
            vec1.push_back(a);
            return ;
        }

        if(root->left){
            sumPath(root->left,vec1,a);
        }

        if(root->right){
            sumPath(root->right,vec1,a);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(!root)
            return false;

        vector<int>vec1;
        int a=0;

        sumPath(root,vec1,a);

       vector<int>::iterator itr;

        itr=find(vec1.begin(),vec1.end(),targetSum);

        if(itr!=vec1.end())
        return true;

        return false;
    }
};


/// Approach-2
/// Runtime: 11 ms, faster than 64.45% of C++ online submissions for Path Sum.
///Memory Usage: 21.3 MB, less than 73.71% of C++ online submissions for Path Sum.

class Solution {
    int flag=0;
public:

    void sumPath(TreeNode *root,int a,int targetsum){
        if(!root)
            return ;
        if(flag==1)
            return ;

         a+=root->val;
        if(!root->left && !root->right){
            if(a==targetsum){
                flag=1;
            }
            return ;
        }

        if(root->left && flag!=1){
            sumPath(root->left,a,targetsum);
        }

        if(root->right && flag!=1){
            sumPath(root->right,a,targetsum);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int a=0;
        sumPath(root,a,targetSum);

        if(flag==1)
            return true;

        return false;
    }

};
