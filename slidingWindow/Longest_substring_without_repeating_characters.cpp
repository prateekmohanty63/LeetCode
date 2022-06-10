#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Runtime: 14 ms, faster than 75.73% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 7.1 MB, less than 87.94% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        if (s.length() == 0 || s.length() == 1)
            return s.length();

        int len = s.length();

        int max = 0, curlen = 0;

        vector<char> vec1;
        vector<char>::iterator it, it1;

        for (int i = 0; i < len; i++)
        {
            it = find(vec1.begin(), vec1.end(), s[i]);

            if (it != vec1.end())
            {
                int count = 1;
                it1 = vec1.begin();

                while (it1 != it)
                {
                    it1++;
                    count++;
                }
                if (it == vec1.begin())
                    vec1.erase(it);

                else
                    vec1.erase(vec1.begin(), ++it);

                vec1.push_back(s[i]);
                curlen++;
                curlen = curlen - count;
            }
            else
            {
                vec1.push_back(s[i]);
                curlen++;
            }

            if (curlen > max)
                max = curlen;
        }
        return max;
    }
};

int main()
{

    return 0;
}