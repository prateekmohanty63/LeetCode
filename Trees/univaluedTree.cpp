#include <iostream>
#include <set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void isUni(TreeNode *root, set<int> &set1)
    {
        if (!root)
            return;

        set1.insert(root->val);

        isUni(root->left, set1);
        isUni(root->right, set1);
    }
    bool isUnivalTree(TreeNode *root)
    {

        set<int> set1;

        isUni(root, set1);

        if (set1.size() == 1)
            return true;

        return false;
    }
};

// 2nd method

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {

        if (root == NULL)
            return true;

        if (root->left)
            if (root->val != root->left->val)
                return false;

        if (root->right)
            if (root->val != root->right->val)
                return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

// 2nd method

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {

        if (root == NULL)
            return true;

        if (root->left)
            if (root->val != root->left->val)
                return false;

        if (root->right)
            if (root->val != root->right->val)
                return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main()
{

    return 0;
}