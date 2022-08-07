#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long int> > dp(n, vector<long long int>(5,0));
        int mod = 1e9+7;
        
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
            
            dp[i][1] = (dp[i-1][2] + dp[i-1][0])%mod;
            
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
            
            dp[i][3] = (dp[i-1][2])%mod;
            
            dp[i][4] = (dp[i-1][3] + dp[i-1][2])%mod;
        }
        
        long long int sum=0;
        
        for(int i=0;i<5;i++){
            sum+=dp[n-1][i];
            sum%=mod;
        }
        
        return sum;
    }
};



// method correct giving error for bigger inputs


class Solution
{
public:
    int MOD = 100000007;
    unordered_map<string, long> dp;
    long helper(int remNo, char prevChar)
    {
        // base case
        if (remNo == 0)
            return 1;

        long total = 0;

        string res = to_string(remNo) + "*" + prevChar;

        if (dp.find(res) != dp.end())
            return dp[res];

        switch (prevChar)
        {
        case 'a':
            total = helper(remNo - 1, 'e') % MOD;
            break;

        case 'e':
            total = (helper(remNo - 1, 'a') + helper(remNo - 1, 'i')) % MOD;
            break;

        case 'i':
            total = (helper(remNo - 1, 'a') + helper(remNo - 1, 'e') + helper(remNo - 1, 'o') + helper(remNo - 1, 'u')) % MOD;
            break;

        case 'o':
            total = (helper(remNo - 1, 'i') + helper(remNo - 1, 'u')) % MOD;
            break;

        case 'u':
            total = (helper(remNo - 1, 'a')) % MOD;
            break;
        }
        return dp[res] = total;
    }
    int countVowelPermutation(int n)
    {

        vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

        long totalCount = 0;

        for (int i = 0; i < 5; i++)
        {
            totalCount = (totalCount + helper(n - 1, vowel[i])) % MOD;
        }
        return (int)totalCount;
    }
};

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