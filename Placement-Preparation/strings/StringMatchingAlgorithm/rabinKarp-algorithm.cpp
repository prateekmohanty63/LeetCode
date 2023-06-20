#include <iostream>
#include<cmath>
#include <unordered_map>

using namespace std;

// Average case time complexity: O(n-m+1);
// worst case time complexity: O((n-m+1)*(m))
// space complexity: O(1)

// hence we can see that the average case time complexity of rabin karp is good
// but the worst case complexity is O(n*m)

// if we keep a normal hash functions , there would be lot of spurious hits

// hence let the hash function be value(digit)*10^m-i

// this type of hashing function is called rabin finger-print function

int main()
{
    unordered_map<char, int> mp;

    string a = "aaaab";
    string b = "aab";

    int n = a.length();
    int m = b.length();

    for (int i = 0; i < 26; i++)
    {
        char ele = char(97 + i);
        mp[ele] = i + 1;
    }

    int target = 0;
    for (int i=0;i<m;i++)
        target += mp[b[i]]*pow(10,m-1-i);

    int currCount = 0;
    int k=0;
    int r=0;

    cout<<"target: "<<" "<<target<<endl;

    for (int i = 0; i < m; i++)
        currCount += (mp[a[i]]*pow(10,m-1-i));

    for (int i = 0; i <=n-m; i++)
    {
       // cout<<currCount<<" ";
        if (target == currCount)
        {
            string currString = a.substr(i, m);
           // cout<<currString<<" ";

            if (currString == b)
                cout << currString<<" "<<"Match found at index: "
                     << " " << i << endl;
        }
      //  int pw=r-()

        // removing the first element from the sliding window sum 
        currCount-=(mp[a[k++]]*pow(10,m-1));

        // multiplying the rest of the sum by 10 , so that it moves left
        currCount*=10;

        // adding the next term to the window
        currCount+=(mp[a[i+m]]*pow(10,0));
        r++;
    }

    // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;

    return 0;
}