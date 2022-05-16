#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

class Solution
{
public:
    void leaveSequence(TreeNode *root, vector<int> &vec1)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            vec1.push_back(root->val);
            return;
        }

        leaveSequence(root->left, vec1);
        leaveSequence(root->right, vec1);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> vec1, vec2;

        leaveSequence(root1, vec1);
        leaveSequence(root2, vec2);

        if (vec1 == vec2)
            return true;

        return false;
    }
};

int main()
{

    return 0;
}