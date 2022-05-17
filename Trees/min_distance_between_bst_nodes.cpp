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

// FASTER THAN 100%

class Solution
{
public:
    void minVal(TreeNode *root, vector<int> &vec1)
    {
        if (!root)
            return;

        minVal(root->left, vec1);
        minVal(root->right, vec1);
        vec1.push_back(root->val);
    }
    int minDiffInBST(TreeNode *root)
    {

        vector<int> vec1;

        minVal(root, vec1);
        int n = vec1.size();

        sort(vec1.begin(), vec1.end());

        int min = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            if (vec1[i + 1] - vec1[i] < min)
                min = vec1[i + 1] - vec1[i];
        }

        return min;
    }
};

int main()
{

    return 0;
}