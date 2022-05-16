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

class Solution
{
public:
    void rightView(TreeNode *root, vector<int> &vec1, int level)
    {
        if (!root)
            return;

        if (vec1.size() == level)
        {
            vec1.push_back(root->val);
        }

        rightView(root->right, vec1, level + 1);
        rightView(root->left, vec1, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> vec1;
        int level = 0;

        rightView(root, vec1, level);

        return vec1;
    }
};

int main()
{

    return 0;
}