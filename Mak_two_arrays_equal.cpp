#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/// Approach-1

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        if (target == arr)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}