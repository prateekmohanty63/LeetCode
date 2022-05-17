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

// 2nd method (will work also if there are nodes with duplicate values)
// Runtime: 1200 ms, faster than 5.01% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
// Memory Usage: 164 MB, less than 58.30% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.

class Solution1
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        if (!original)
            return NULL;

        if (original == target)
            return cloned;

        TreeNode *l = getTargetCopy(original->left, cloned->left, target);
        TreeNode *r = getTargetCopy(original->right, cloned->right, target);

        if (l != NULL)
            return l;

        if (r != NULL)
            return r;

        return NULL;
    }
};

int main()
{

    return 0;
}