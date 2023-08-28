#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPali(string b)
{
    string c = b;
    reverse(b.begin(), b.end()); // -- O(N)

    return c == b;
}

string longPali(string a)
{
    string res = "";
    int n = a.length();
    int max = -1;

    for (int i = 0; i < n; i++) //  --- O(N)
    {
        for (int j = i + 1; j < n; j++) // --- O(N)
        {
            int len = j - i;
            string r = a.substr(i, len);

            if (isPali(r) && len > max) // --- O(N)
            {
                max = len;
                res = r;
            }
        } // Total O(N^3)
    }
    return res;
}

string longPaliop(string a)
{
    string res;
    int max = -1;

    int n = a.length();

    for (int i = 0; i < n; i++)
    {
        /// Odd length palindrome
        int l, r;
        l = i, r = i;

        while (l >= 0 && r < n && a[l] == a[r])
        {
            if (r - l + 1 > max)
            {
                max = r - l + 1;
                res = a.substr(l, r - l + 1);
            }
            l--;
            r++;
        }

        /// Even length palindrome
        l = i, r = i + 1;
        while (l >= 0 && r < n && a[l] == a[r])
        {
            if (r - l + 1 > max)
            {
                max = r - l + 1;
                res = a.substr(l, r - l + 1);
            }
            l--, r++;
        }
    }
    return res;
}

int main()
{
    string a;
    cin >> a;
    cout << longPali(a) << endl;
    cout << longPaliop(a);
    return 0;
}