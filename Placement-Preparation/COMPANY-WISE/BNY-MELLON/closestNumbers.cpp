#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>vec;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int minim=INT_MAX;

    for(int i=0;i<n-1;i++)
    {
        minim=min(minim,vec[i+1]-vec[i]);
    } 

    for(int i=0;i<n-1;i++)
    {
        if(vec[i+1]-vec[i]==minim)
        cout<<vec[i]<<" "<<vec[i+1]<<endl;
    }
    return 0;
}