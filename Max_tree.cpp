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
    int maxim(vector<int> nums, int l, int r)
    {
        int index = -1;
        int min = -1;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] > min)
            {
                min = nums[i];
                index = i;
            }
        }
        return index;
    }

    TreeNode *solve(vector<int> nums, int l, int r)
    {

        if (l > r)
            return NULL;

        int i = maxim(nums, l, r);
        TreeNode *newNode = new TreeNode(nums[i]);

        newNode->left = solve(nums, l, i - 1);
        newNode->right = solve(nums, i + 1, r);

        return newNode;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {

        if (nums.size() == 0)
            return NULL;

        TreeNode *res = solve(nums, 0, nums.size() - 1);

        return res;
    }
};