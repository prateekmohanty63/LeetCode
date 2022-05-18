#include <iostream>
#include <map>
#include <climits>
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
    void findMode(TreeNode *root, map<int, int> &map1)
    {
        if (!root)
            return;

        map1[root->val]++;

        findMode(root->left, map1);
        findMode(root->right, map1);
    }
    vector<int> findMode(TreeNode *root)
    {

        int max = INT_MIN;
        vector<int> res;

        map<int, int> map1;

        findMode(root, map1);

        map<int, int>::iterator itr = map1.begin();

        for (itr = map1.begin(); itr != map1.end(); itr++)
        {
            if (itr->second > max)
                max = itr->second;
        }

        for (itr = map1.begin(); itr != map1.end(); itr++)
        {
            if (itr->second == max)
            {
                res.push_back(itr->first);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}