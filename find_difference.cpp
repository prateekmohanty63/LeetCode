#include <iostream>
using namespace std;

// approach-1

class Solution
{
public:
    char findTheDifference(string s, string t)
    {

        if (s.size() == 0)
            return t[0];

        int a = 0, b = 0;

        for (int i = 0; i < s.size(); i++)
        {
            a += (int)(s[i]);
        }

        for (int i = 0; i < t.size(); i++)
        {
            b += (int)(t[i]);
        }
        int k = b - a;

        return char(k);
    }
};

// A very unique way also exists try it

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char v = 0;
        for (char c : s)
            v ^= c;
        for (char c : t)
            v ^= c;
        return v;
    }
};
int main()
{

    return 0;
}