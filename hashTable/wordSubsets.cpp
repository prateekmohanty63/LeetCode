#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    bool isSubset(string text, string pattern)
    {
        if (text == pattern)
            return true;

        unordered_map<char, int> textMap;

        for (int i = 0; i < text.length(); i++)
        {
            textMap[text[i]]++;
        }

        for (int i = 0; i < pattern.length(); i++)
        {
            char a = pattern[i];
            if (textMap.find(a) == textMap.end())
                return false;

            if (textMap.find(a) != textMap.end())
            {
                int b = textMap[a];
                cout << b << " ";
                if (b <= 0)
                    return false;
                textMap[a]--;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {

        vector<string> res;

        int n = words1.size();
        int m = words2.size();

        for (int i = 0; i < n; i++)
        {
            string text = words1[i];
            int numberOfSubsets = 0;
            for (int j = 0; j < m; j++)
            {
                string pattern = words2[j];
                if (isSubset(text, pattern))
                {
                    numberOfSubsets++;
                }
            }
            if (numberOfSubsets == m)
                res.push_back(words1[i]);
        }

        return res;
    }
};

int main()
{

    return 0;
}