
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

 /// 1st Approach ( Too slow)
 /// Runtime: 23 ms, faster than 5.00% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
 /// Memory Usage: 18.4 MB, less than 15.42% of C++ online submissions for Sum of Root To Leaf Binary Numbers.

class Solution {
public:
    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

    void binarySum(TreeNode *root ,vector<string> &vec1,string a)
    {
        if(!root)
        return ;

        a+=to_string(root->val);


         if(!root->left && !root->right){
            vec1.push_back(a);
            a="";
        }

        if(root->left)
        binarySum(root->left,vec1,a);

        if(root->right)
        binarySum(root->right,vec1,a);

        return ;
    }
    int sumRootToLeaf(TreeNode* root) {

        if(!root->left && !root->right)
            return root->val;
        string a;
        vector<string>vec1;

        binarySum(root,vec1,a);

        int res;

        for(int i=0;i<vec1.size();i++){
           res+=binaryToDecimal(vec1[i]);
        }

        return res;
    }
};


/// 2nd approach

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

 ///  Runtime: 18 ms, faster than 7.10% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
 /// Memory Usage: 18.5 MB, less than 13.93% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
class Solution {
public:

    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;

    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

    void binarySum(TreeNode *root,string a)
    {
        if(!root){
            return ;
        }

        a+=to_string(root->val);

        if(!root->left && !root->right){
            res+=binaryToDecimal(a);
            a="";
            return ;
        }
        if(root->left){
            binarySum(root->left,a);
        }

        if(root->right){
            binarySum(root->right,a);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;

        string a;
        binarySum(root,a);
        return res;

    }
};

/// 3rd approach

/// We can remove the function we are using for binary too decimal conversion

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

 /// Runtime: 10 ms, faster than 29.55% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
 ///  Memory Usage: 16.6 MB, less than 72.35% of C++ online submissions for Sum of Root To Leaf Binary Numbers.

class Solution {
    int res=0;
public:

    void preorder(TreeNode *root,int currnum)
    {
         if(!root)
             return ;

        currnum=currnum<<1 | root->val;

        if(!root->left && !root->right){
            res+=currnum;
            currnum=0;
            return ;
        }

        if(root->left){
            preorder(root->left,currnum);
        }
        if(root->right){
            preorder(root->right,currnum);
        }

    }
    int sumRootToLeaf(TreeNode* root) {
        int a;
        preorder(root,0);

        return res;
    }
};

