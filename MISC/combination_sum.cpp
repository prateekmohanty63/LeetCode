#include <iostream>
#include <vector>
using namespace std;

/// 1st approach
/// Not working

class Solution
{
    int binarySearch(vector<int> arr, int l, int r, int x)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);

            return binarySearch(arr, mid + 1, r, x);
        }

        return -1;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &cand, int target)
    {

        vector<vector<int>> res;

        for (int i = 0; i < cand.size(); i++)
        {
            vector<int> vec1;
            int sum = cand[i];
            if (sum == target)
            {
                vec1.push_back(sum);
                res.push_back(vec1);
                break;
            }
            if (target % cand[i] == 0)
            {
                for (int j = 0; j < target % cand[i]; j++)
                {
                    vec1.push_back(cand[i]);
                }
                res.push_back(vec1);
                break;
            }
            else if (target % cand[i] != 0)
            {
                int r = 0;
                for (int j = 0; j < target / cand[i]; j++)
                {
                    r += cand[j];
                    int x = target - r;
                    vec1.push_back(cand[i]);
                    if (binarySearch(cand, i + 1, cand.size() - 1, x) != -1)
                    {
                        int m = binarySearch(cand, i + 1, cand.size() - 1, x);
                        vec1.push_back(cand[m]);
                        res.push_back(vec1);
                        break;
                    }
                }
                int a = target % cand[i];
                int index = binarySearch(cand, i + 1, cand.size() - 1, a);
                if (index != -1)
                {
                    vec1.push_back(a);
                    res.push_back(vec1);
                    break;
                }
                // res.push_back(vec1);
            }
            for (int j = i + 1; j < cand.size(); j++)
            {
                sum += cand[j];
                if (sum == target)
                {
                    vec1.push_back(cand[j]);
                    res.push_back(vec1);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}