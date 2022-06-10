#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {

        int n = patterns.size();
        int m = word.size();
        int count = 0;

        vector<string> substrings;
        cout << n << " " << m;

        // generate all substring of word

        for (int i = 0; i < m; i++)
        {
            string res;
            res = word[i];
            substrings.push_back(res);
            for (int j = i + 1; j < m; j++)
            {
                res += word[j];
                substrings.push_back(res);
            }
        }

        // now search for word in patten array in substring array
        vector<string>::iterator it;

        for (int i = 0; i < n; i++)
        {
            string searchString = patterns[i];
            it = find(substrings.begin(), substrings.end(), searchString);

            if (it != substrings.end())
                count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}