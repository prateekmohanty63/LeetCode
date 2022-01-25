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

int main()
{

    return 0;
}