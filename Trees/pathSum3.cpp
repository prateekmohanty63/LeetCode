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
    void pathcount(TreeNode *root, int targetSum, int &totalCount, vector<int> vec1)
    {
        if (!root)
        {
            return;
        }

        vec1.push_back(root->val);

        pathcount(root->left, targetSum, totalCount, vec1);
        pathcount(root->right, targetSum, totalCount, vec1);
        long long int sum = 0;

        for (int i = vec1.size() - 1; i >= 0; i--)
        {
            sum += vec1[i];

            if (sum == targetSum)
                totalCount++;
        }

        vec1.pop_back();
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        int totalCount = 0;
        vector<int> vec1;

        pathcount(root, targetSum, totalCount, vec1);

        return totalCount;
    }
};

int main()
{

    return 0;
}