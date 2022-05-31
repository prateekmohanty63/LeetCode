#include <iostream>
#include <set>
#include <math.h>
using namespace std;

// Runtime: 1783 ms, faster than 5.03% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
// Memory Usage: 91.4 MB, less than 16.98% of C++ online submissions for Check If a String Contains All Binary Codes of Size K.

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        int n = s.length();

        set<string> set1;
        int m = pow(2, k);

        for (int i = 0; i <= n - k; i++)
        {
            string a;
            for (int j = i; j < k + i; j++)
            {
                a += s[j];

                // break;
            }

            set1.insert(a);
        }

        // set elements
        set<string>::iterator itr;

        for (itr = set1.begin(); itr != set1.end(); itr++)
            cout << *itr << " ";

        if (set1.size() == m)
            return true;

        return false;
    }
};

int main()
{

    return 0;
}