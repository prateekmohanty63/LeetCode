#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1st method ( but will only work if there are no duplicate values allowed in the tree)
// Runtime: 536 ms, faster than 90.21% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
// Memory Usage: 163.9 MB, less than 58.30% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.

class Solution
{
public:
    TreeNode *tar;
    void TreeSearch(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // base case
        if (!cloned)
            return;

        // given condition
        if (target->val == cloned->val)
        {
            tar = cloned;
        }

        // recursive case

        TreeSearch(original, cloned->left, target);
        TreeSearch(original, cloned->right, target);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        TreeSearch(original, cloned, target);

        return tar;
    }
};

int main()
{

    return 0;
}