#include <iostream>
#include <vector>
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

// Runtime: 35 ms, faster than 80.77% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 30.8 MB, less than 64.50% of C++ online submissions for Count Complete Tree Nodes.

// Time complexity of this code is O(n)
// in question time complexity of less than o(n) has been asked

class Solution
{
public:
    void countNode(TreeNode *root, int &count)
    {
        if (!root)
            return;

        count++;

        countNode(root->left, count);
        countNode(root->right, count);
    }
    int countNodes(TreeNode *root)
    {
        int count = 0;

        countNode(root, count);

        return count;
    }
};

int main()
{

    return 0;
}