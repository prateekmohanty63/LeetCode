#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> res;

        int n = strs.size();

        vector<int> taken(n, -1);

        if (n == 1)
        {
            vector<string> vec1;
            vec1.push_back(strs[0]);
            res.push_back(vec1);
            return res;
        }

        for (int i = 0; i < n; i++)
        {
            string a = strs[i];
            string temp = a;
            vector<string> vec1;
            sort(temp.begin(), temp.end());
            vec1.push_back(a);

            for (int j = i + 1; j < n; j++)
            {
                string e = strs[j];
                string temp1 = e;
                sort(temp1.begin(), temp1.end());
                if (temp == temp1 && taken[j] == -1)
                {
                    vec1.push_back(e);
                    taken[j] = 0;
                    taken[i] = 0;
                }
            }

            if (vec1.size() != 1)
                res.push_back(vec1);
        }

        for (int i = 0; i < n; i++)
        {
            vector<string> vec1;
            if (taken[i] == -1)
            {
                vec1.push_back(strs[i]);
                res.push_back(vec1);
            }
        }
        for (int i = 0; i < n; i++)
            cout << taken[i] << " ";

        return res;
    }
};

int main()
{

    return 0;
}