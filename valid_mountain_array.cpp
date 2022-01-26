#include <iostream>
#include <vector>
using namespace std;

// Approach-1

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {

        int n = arr.size();
        int flag = 0, flag1 = 0;

        if (n < 3)
            return false;

        int i = 0;

        while (i < n - 1 && arr[i] < arr[i + 1])
        {
            flag1 = 1;
            i++;
        }
        cout << i << " ";
        while (i < n - 1 && arr[i] > arr[i + 1])
        {
            flag = 1;
            i++;
        }
        cout << flag;

        if (flag != 1 || flag1 != 1)
            return false;

        if (i == n - 1)
            return true;

        return false;
    }
};

int main()
{

    return 0;
}