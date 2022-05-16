#include <iostream>
#include <vector>
#include <map>
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
    void getKthElement(TreeNode *root, vector<int> &vec1)
    {
        if (!root)
            return;

        vec1.push_back(root->val);

        getKthElement(root->left, vec1);
        getKthElement(root->right, vec1);
    }
    int kthSmallest(TreeNode *root, int k)
    {

        vector<int> vec1;

        getKthElement(root, vec1);

        sort(vec1.begin(), vec1.end());

        int count = 0;

        map<int, int> map1;

        for (int i = 0; i < vec1.size(); i++)
        {
            map1[vec1[i]]++;
        }

        auto it = map1.begin();

        while (k != 1)
        {
            k--;
            it++;
        }
        return it->first;
    }
};

int main()
{

    return 0;
}