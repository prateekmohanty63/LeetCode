
/// First approach
/// Did not work

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string>res;
        if(root->left==NULL && root->right==NULL){
            int c=root->val;
            string a=to_string(c);
            res.push_back(a);
            return res;
        }
        int c;
        string b,a;
        if(root){
        if(root->left!=NULL){
             c=root->val;
             a=to_string(c);
            if(root->left || root->right){
                string b="->";
                a=a+b;
            }
            //res.push_back(a);
            binaryTreePaths(root->left);
        }
        if(root->right!=NULL){
            c=root->val;
            a=to_string(c);
            if(root->left || root->right){
                string b="->";
                a=a+b;
            }
            //res.push_back(e);
            binaryTreePaths(root->right);
        }
         res.push_back(a);
        }
        return res;
    }
};


/// 2nd approach
///  Runtime: 9 ms, faster than 10.27% of C++ online submissions for Binary Tree Paths.
///Memory Usage: 13.3 MB, less than 30.62% of C++ online submissions for Binary Tree Paths.


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
    vector<string>res;
    void Answer(TreeNode *root,string a){
        if(!root)
            return ;
        a+=to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(a);
            a="";
        }

        a+="->";
        Answer(root->left,a);
        Answer(root->right,a);
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        string a="";
        Answer(root,a);
        return res;
    }
};


/// 3rd approach
///Runtime: 6 ms, faster than 35.90% of C++ online submissions for Binary Tree Paths.
///Memory Usage: 13 MB, less than 61.27% of C++ online submissions for Binary Tree Paths.

class Solution {
    vector<string>res;
public:
    void Answer(TreeNode *root,string a,vector<string>&res){
        if(!root)
            return ;
        a+=to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(a);
            a="";
        }

        a+="->";
        if(root->left){
        Answer(root->left,a);
        }
        if(root->right){
        Answer(root->right,a);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string a="";
        Answer(root,a);
        return res;
    }
};

/// 4th approach

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

 /// Runtime: 3 ms, faster than 79.34% of C++ online submissions for Binary Tree Paths.
///Memory Usage: 13 MB, less than 61.27% of C++ online submissions for Binary Tree Paths.
class Solution {
public:
    void Answer(TreeNode *root,string a,vector<string>&res){
        if(!root)
            return ;
        a+=to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(a);
            a="";
        }

        a+="->";
        if(root->left){
        Answer(root->left,a,res);
        }
        if(root->right){
        Answer(root->right,a,res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string a="";
        vector<string>vec1;
        Answer(root,a,vec1);
        return vec1;
    }
};
