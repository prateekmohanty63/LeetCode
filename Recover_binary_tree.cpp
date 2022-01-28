#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Approach-1
/// Time complexity if fine
/// But this has to be implemented using O(1) space
/// Here it is taking O(N) space

/**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution
{
public:
    int i = 0;
    void inorder(TreeNode *root, vector<int> &vec1)
    {

        if (root == NULL)
            return;
        inorder(root->left, vec1);
        vec1.push_back(root->val);
        inorder(root->right, vec1);
    }
    void builtTree(TreeNode *root, vector<int> vec1)
    {
        if (root == NULL)
            return;
        builtTree(root->left, vec1);
        root->val = vec1[i++];
        builtTree(root->right, vec1);
    }
    void recoverTree(TreeNode *root)
    {

        vector<int> vec1;
        inorder(root, vec1);
        sort(vec1.begin(), vec1.end());

        builtTree(root, vec1);
    }
};

int main()
{

    return 0;
}
