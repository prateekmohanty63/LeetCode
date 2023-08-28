#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int n;
    cin>>n;

    string arr[n];

    string a;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    string b;

    for(int i=0;i<n;i++)
    {
        a+=arr[i];
    }

    set<string> set1;

    for(int i=0;i<a.size();i++){
        set1.insert(a[i]);
    }
}

