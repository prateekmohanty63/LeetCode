#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec1.push_back(a);
    }

    //vec1.push_back(1000001);

    vector<int>::iterator it;

    for (int i = 0; i < n - 1; i++)
    {
        it = find(vec1.begin() + i + 1, vec1.end(), vec1[i]);
        if (it != vec1.end())
            cout << vec1[i] << " ";
    }

    return 0;
}