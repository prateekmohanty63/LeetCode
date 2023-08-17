#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec1,vec2;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec1.push_back(a);

    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec2.push_back(a);
    }

    sort(vec1.begin(),vec1.end(),greater<int>());
    sort(vec2.begin(),vec2.end());

    int res=0;

    for(int i=0;i<n;i++)
    {
        res+=(i+1)*(vec2[i]-vec1[i]);
    }
     cout<<res<<" ";
    return 0;
}