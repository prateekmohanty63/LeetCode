#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    // condition to be satisfied

    bool correctSequence(string a)
    {
        for (int i = 0; i < a.size() - 1; i++)
        {
            if (a[i] == 'a')
            {
                if (a[i + 1] != 'e')
                    return false;
            }
            if (a[i] == 'e')
            {
                if (a[i + 1] != 'a' && a[i + 1] != 'i')
                    return false;
            }
            if (a[i] == 'i')
            {
                if (a[i + 1] == 'i')
                    return false;
            }
            if (a[i] == 'o')
            {
                if (a[i + 1] != 'i' && a[i + 1] != 'u')
                    return false;
            }
            if (a[i] == 'u')
            {
                if (a[i + 1] != 'a')
                    return false;
            }
        }
        return true;
    }

    int countPermutation(int n, vector<char> &vowel, string permu, unordered_map<string, int> &dp)
    {

        // base case
        if (permu.size() == n)
        {
            if (correctSequence(permu))
                return dp[permu] = 1;

            else
                return dp[permu] = 0;
        }
        if (dp.find(permu) != dp.end())
            return dp[permu];
        int count = 0;
        for (int i = 0; i < vowel.size(); i++)
        {
            count += countPermutation(n, vowel, permu + vowel[i], dp);
        }
        return dp[permu] = count;
    }

    int countVowelPermutation(int n)
    {

        if (n == 1 || n == 2)
            return 5 * n;

        vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        string permu;
        unordered_map<string, int> dp;

        return countPermutation(n, vowel, permu, dp);
    }
};

int main()
{

    return 0;
}