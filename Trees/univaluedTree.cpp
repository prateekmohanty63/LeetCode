#include <iostream>
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

int main()
{

    return 0;
}