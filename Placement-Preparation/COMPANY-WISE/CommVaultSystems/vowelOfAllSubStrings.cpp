#include <iostream>
using namespace std;



class Solution
{
public:
    bool isVowel(char a)
    {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    long long countVowels(string word)
    {

        int n = word.length();
        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            if (isVowel(word[i]))
            {
                res += (long long)(i + 1) * (n - i);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}