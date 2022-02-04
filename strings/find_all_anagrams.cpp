#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Approach-1
/// Gives TLE

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        vector<int> res;
        sort(p.begin(), p.end());

        int n = s.size();
        int m = p.size();
        // string a="";

        for (int i = 0; i <= n - m; i++)
        {
            string a;
            for (int j = 0; j < m; j++)
            {
                a += s[i + j];
            }
            sort(a.begin(), a.end());
            if (a == p)
            {
                res.push_back(i);
                cout << a << " " << i << endl;
            }
            //a="";
        }
        return res;
    }
};

/// 2 approach
/// sliding window concept

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {

        int n = s.size();
        int a = s.size();
        int b = p.size();

        vector<int> res;

        if (a < b)
            return {};

        vector<int> freq(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < b; i++)
        {
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        if (freq == window)
            res.push_back(0);

        for (int i = b; i < a; i++)
        {
            window[s[i - b] - 'a']--;
            window[s[i] - 'a']++;

            if (window == freq)
                res.push_back(i - b + 1);
        }

        return res;
    }
};

int main()
{

    return 0;
}