#include <iostream>
#include <unordered_map>

using namespace std;

// Average case time complexity: O(n-m+1);
// worst case time complexity: O((n-m+1)*(m))
// space complexity: O(1)

// hence we can see that the average case time complexity of rabin karp is good
// but the worst case complexity is O(n*m)


int main()
{
    unordered_map<char, int> mp;

    string a = "aaabaab";
    string b = "aab";

    int n = a.length();
    int m = b.length();

    for (int i = 0; i < 26; i++)
    {
        char ele = char(97 + i);
        mp[ele] = i + 1;
    }

    int target = 0;
    for (auto it : b)
        target += mp[it];

    int currCount = 0;
    int k=0;

    cout<<"target: "<<" "<<target<<endl;

    for (int i = 0; i < m; i++)
        currCount += mp[a[i]];

    for (int i = 0; i <=n-m; i++)
    {
        //cout<<currCount<<" ";
        if (target == currCount)
        {
            string currString = a.substr(i, m);
           // cout<<currString<<" ";

            if (currString == b)
                cout << currString<<" "<<"Match found at index: "
                     << " " << i << endl;
        }
        currCount-=mp[a[k++]];

        if(i+m<n)
        currCount+=mp[a[i+m]];
    }

    // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;

    return 0;
}