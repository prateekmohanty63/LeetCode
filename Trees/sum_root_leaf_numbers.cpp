#include <iostream>
#include <vector>
#include <math.h>
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
    void sumfunc(TreeNode *root, vector<int> vec1, vector<vector<int>> &res)
    {
        if (!root)
            return;

        vec1.push_back(root->val);

        if (!root->left && !root->right)
        {
            res.push_back(vec1);
            return;
        }

        sumfunc(root->left, vec1, res);
        sumfunc(root->right, vec1, res);
    }
    int sumNumbers(TreeNode *root)
    {

        vector<int> vec1;
        vector<vector<int>> res;

        int sum = 0;

        sumfunc(root, vec1, res);

        //         for(int i=0;i<res.size();i++)
        //         {
        //             for(int j=0;j<res[i].size();j++)
        //             {
        //                 cout<<res[i][j]<<" ";
        //             }
        //             cout<<endl;
        //         }

        for (int i = 0; i < res.size(); i++)
        {
            int sum1 = 0;
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " ";
                sum1 += res[i][j] * pow(10, res[i].size() - j - 1);
            }
            sum += sum1;
        }
        return sum;
    }
};

int main()
{

    return 0;
}