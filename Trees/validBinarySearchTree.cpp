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

// 1st method

// Runtime: 25 ms, faster than 15.80% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 21.8 MB, less than 16.80% of C++ online submissions for Validate Binary Search Tree.

class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vec1)
    {
        if (!root)
            return;
        inorder(root->left, vec1);
        vec1.push_back(root->val);
        inorder(root->right, vec1);
    }

    bool isValidBST(TreeNode *root)
    {

        vector<int> vec1;

        inorder(root, vec1);

        for (int i = 0; i < vec1.size(); i++)
            cout << vec1[i] << " ";

        int n = vec1.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (vec1[i + 1] <= vec1[i])
                return false;
        }

        return true;
    }
};

int main()
{

    return 0;
}