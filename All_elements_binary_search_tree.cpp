#include <iostream>
#include <vector>
using namespace std;

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

/// OPTIMAL APPROACH

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
class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {

        vector<int> res;
        stack<TreeNode *> stk1, stk2;

        while (root1 || root2 || !stk1.empty() || !stk2.empty())
        {
            while (root1 != NULL)
            {
                stk1.push(root1);
                root1 = root1->left;
            }

            while (root2 != NULL)
            {
                stk2.push(root2);
                root2 = root2->left;
            }

            if (stk2.empty() || (!stk1.empty() && stk1.top()->val <= stk2.top()->val))
            {
                root1 = stk1.top();
                stk1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            }
            else
            {
                root2 = stk2.top();
                stk2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }

        return res;
    }
};

class Solution
{
public:
    vector<int> vec1;
    void inorder(TreeNode *root)
    {

        if (root == NULL)
            return;

        inorder(root->left);

        vec1.push_back(root->val);

        inorder(root->right);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {

        /// Inorder traversal gives BST in ascending order

        inorder(root1);
        inorder(root2);

        sort(vec1.begin(), vec1.end());

        return vec1;
    }
};

/// Approach-2
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vec1)
    {

        if (root == NULL)
            return;

        inorder(root->left, vec1);

        vec1.push_back(root->val);

        inorder(root->right, vec1);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {

        /// Inorder traversal gives BST in ascending order
        vector<int> vec1;
        inorder(root1, vec1);
        inorder(root2, vec1);

        sort(vec1.begin(), vec1.end());

        return vec1;
    }
};

int main()
{

    return 0;
}