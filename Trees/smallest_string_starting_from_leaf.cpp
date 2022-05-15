#include <iostream>
#include <vector>
#include <algorithm>
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
    void sumfunc(TreeNode *root, string path, vector<string> &res)
    {
        if (!root)
            return;

        int a = root->val + 97;
        char b = (char)a;
        path += b;

        if (!root->left && !root->right)
        {
            reverse(path.begin(), path.end());
            res.push_back(path);

            return;
        }

        sumfunc(root->left, path, res);
        sumfunc(root->right, path, res);
    }
    string smallestFromLeaf(TreeNode *root)
    {

        string path;
        vector<string> res;

        sumfunc(root, path, res);

        sort(res.begin(), res.end());

        return res[0];
    }
};

int main()
{

    return 0;
}