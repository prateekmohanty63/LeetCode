#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vec;

    for(int i=0;i<n;i++)
    {
        int a;
        int b;
        cin>>a;
        cin>>b;
        vec.push_back({a,b});
    }
    int currTime=0;
    int res=INT_MIN;
    int id;

    for(int i=0;i<n;i++)
    {
        if((vec[i][1]-currTime)>res)
        {
            res=vec[i][1]-currTime;
            id=vec[i][0];
        }
        currTime=vec[i][1];
    }
    cout<<"Longest shift is of "<<res<<" by employee "<<id<<endl;
    return 0;
}