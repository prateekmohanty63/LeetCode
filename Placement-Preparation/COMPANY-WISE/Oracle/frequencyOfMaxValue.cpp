#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int main()
{
    vector<int>nums;
    vector<int>q;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        q.push_back(a);
    }

    unordered_map<int,int>mp;
    unordered_map<int,int>freq;
    vector<int>ans(n,1);
    int currMax=INT_MIN;

    for(int i=n-1;i>=0;i--)
    {
        freq[nums[i]]++;
        currMax=max(currMax,nums[i]);
        ans[i]=freq[currMax];
    }

    for(auto it:ans)cout<<it<<" ";

    return 0;
}