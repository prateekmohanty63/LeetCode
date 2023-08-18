#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec={2,3,3,3,2,1};
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        mp[vec[i]]++;
    }
    int res=0;
    int prevCount=-1;
    for(int i=0;i<n;i++)
    {
        int ele=vec[i];
        int freq=mp[ele];
        
        if(freq!=0){
        if(prevCount==-1)
        {
            res++;
            prevCount=freq;
            mp[ele]-=freq;
        }
        else{
            
        }
        }
    }


    return 0;
}