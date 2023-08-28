#include <iostream>
#include <vector>
using namespace std;

/// Approach-1
/// Brute force
/// But here TLE errors occurs

int findMaximumXOR(vector<int> &nums, int &e, int &f)
{

    int max = -1;
    int n = nums.size();
    int a, b;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            int num1 = nums[i] ^ nums[j];
            if (num1 > max)
            {
                e = nums[i];
                f = nums[j];
                max = num1;
            }
        }
    }
    return max;
}

/// Approach-2
/// We have to use trie data structure here

int main()
{
    int n;
    cin >> n;
    int c, b;

    vector<int> vec1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }
    cout << findMaximumXOR(vec1, c, b) << endl;
    cout << c << " " << b;
    return 0;
}