
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

int main()
{

    return 0;
}
class Solution
{
public:
    void TreeSum(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> vec1)
    {
        if (!root)
            return;

        vec1.push_back(root->val);
        // cout<<sum<<" ";

        if (!root->right && !root->left && root->val == targetSum)
        {
            res.push_back(vec1);
            return;
        }

        targetSum -= root->val;

        TreeSum(root->left, targetSum, res, vec1);
        TreeSum(root->right, targetSum, res, vec1);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> vec1;
        vector<vector<int>> vec;
        int sum = 0;
        TreeSum(root, targetSum, vec, vec1);

        return vec;
    }
};

// 2nd method
// Runtime: 41 ms, faster than 7.63% of C++ online submissions for Path Sum II.
// Memory Usage: 38.7 MB, less than 18.59% of C++ online submissions for Path Sum II.

class Solution
{
public:
    void TreeSum(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> vec1, int sum)
    {
        if (!root)
            return;

        vec1.push_back(root->val);
        sum += root->val;
        // cout<<sum<<" ";

        if (!root->right && !root->left && sum == targetSum)
        {
            res.push_back(vec1);
            return;
        }

        TreeSum(root->left, targetSum, res, vec1, sum);
        TreeSum(root->right, targetSum, res, vec1, sum);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> vec1;
        vector<vector<int>> vec;
        int sum = 0;
        TreeSum(root, targetSum, vec, vec1, sum);

        return vec;
    }
};