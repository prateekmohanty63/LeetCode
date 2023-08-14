#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int>generatePrimes(int num)
{
    vector<int>isPrime(num+1,1);

    for(int p=2;p*p<=num;p++)
    {
        if(isPrime[p]==true)
        {
            for(int i=p*p;i<=num;i+=p)
            isPrime[i]=false;
        }
    }
    vector<int>res;
    for(int i=1;i<=num;i++)
    {
        if(isPrime[i])res.push_back(i);
    }
    return res;
}

void Union(vector<int>&a,vector<int>&b)
{
     map<int,bool>mp;

     for(auto it:a)mp[it]=true;

     for(auto it:b)mp[it]=true;

     for(auto it:mp)cout<<it.first<<" ";
}

void intersection(vector<int>&a,vector<int>&b)
{
    unordered_map<int,int>mp;
    for(auto it:a)mp[it]=true;

    for(int i=0;i<b.size();i++)
    {
        if(mp.find(b[i])!=mp.end())
        cout<<b[i]<<" ";
    }
}


bool sumPossible(vector<int>&vec,int target,int ind)
{
     if(target==0)return true;

     if(ind>=vec.size())return false;

     if(vec[ind]<=target)
     return sumPossible(vec,target-vec[ind],ind+1) || sumPossible(vec,target,ind+1);

     else return sumPossible(vec,target,ind+1);
}


int main()
{
    int n;
    int k;
    cin>>n>>k;

    vector<int>a,b;

    for(int i=0;i<n;i++)
    {
        int e;
        cin>>e;
        a.push_back(e);
    }
    for(int i=0;i<n;i++)
    {
        int e;
        cin>>e;
        b.push_back(e);
    }

    vector<int>allSum;
   

    for(int i=0;i<n-k;i++)
    {
        int sum=0;
        for(int j=i;j<n;j+=k)
        {
            sum+=a[j];
        }
        allSum.push_back(sum);
    }

    for(auto it:allSum)cout<<it<<" ";
    cout<<endl;

   int flag=0;
    for(auto it:allSum)
    {
        vector<int>vec=generatePrimes(it);
        cout<<"primes: ";
        for(auto itr:vec)cout<<itr<<" ";
        cout<<endl;
        if(!sumPossible(vec,it,0))
        {
            cout<<"NOT POSSIBLE: "<<it<<" ";
            cout<<endl;
            intersection(a,b);
            flag=1;
            break;
        }
        
    }
    //cout<<flag<<" ";
    if(flag==0)Union(a,b);
    return 0;
}