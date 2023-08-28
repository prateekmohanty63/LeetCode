#include <iostream>
#include <vector>
#include <map>
using namespace std;

/// Approach-1
/// Time complexity id very high

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        vector<int> res;
        map<int, char> map1;

        int n = boxes.size();

        if (n == 1)
        {
            res.push_back(0);
            return res;
        }

        for (int i = 0; i < n; i++)
        {
            map1[i] = boxes[i];
        }

        map<int, char>::iterator itr;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (itr = map1.begin(); itr != map1.end(); itr++)
            {
                if (itr->first != i && itr->second == '1')
                {
                    count += abs(i - itr->first);
                }
            }
            res.push_back(count);
        }

        return res;
    }
};

/// Approach-2

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        vector<int> res(boxes.size(), 0);
        int n = boxes.size();

        /// Left Array
        vector<int> left(boxes.size(), 0);

        /// Right Array
        vector<int> right(boxes.size(), 0);

        int balls = boxes[0] - '0';
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] + balls;
            balls += boxes[i] - '0';
        }

        balls = boxes[boxes.size() - 1] - '0';

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] + balls;
            balls += boxes[i] - '0';
        }

        for (int i = 0; i < n; i++)
        {
            res[i] = left[i] + right[i];
        }
        return res;
    }
};

int main()
{

    return 0;
}