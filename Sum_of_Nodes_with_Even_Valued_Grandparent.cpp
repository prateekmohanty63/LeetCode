
/// Approach-1

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

/// Runtime: 78 ms, faster than 18.87% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
///Memory Usage: 41.3 MB, less than 80.28% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.

class Solution {
public:
    void grandparent(TreeNode *root,int &sum){
        if(!root) return ;

        if(root->left){
        if(root->val%2==0 && root->left->left){
            sum+=root->left->left->val;
        }

        if(root->val%2==0 && root->left->right)
            sum+=root->left->right->val;
        }

        if(root->right){
        if(root->val%2==0 && root->right->left)
            sum+=root->right->left->val;
        if(root->val%2==0 && root->right->right)
            sum+=root->right->right->val;
        }
        if(root->left)
            grandparent(root->left,sum);
        if(root->right)
            grandparent(root->right,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {

        if(!root->left && !root->right) return 0;

        int sum=0;
         grandparent(root,sum);

        return sum;
    }
};


/// approach -2

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

 /// Runtime: 63 ms, faster than 31.98% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
/// Memory Usage: 41.4 MB, less than 80.28% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.


class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {

        if(!root) return 0;

        int sum=0;

        if(root->val%2==0){
            if(root->left && root->left->left)
                sum+=root->left->left->val;
             if(root->left && root->left->right)
                sum+=root->left->right->val;
             if(root->right && root->right->left)
                sum+=root->right->left->val;
             if(root->right && root->right->right)
                sum+=root->right->right->val;
        }

        if(root->left)
        sum+=sumEvenGrandparent(root->left);

        if(root->right)
            sum+=sumEvenGrandparent(root->right);

        return sum;
    }
};
