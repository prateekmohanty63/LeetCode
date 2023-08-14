#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> sieve(int n)
{
    vector<int>isPrime(n+1,true);

    for(int p=2;p*p<=n;p++)
    {
        if(isPrime[p])
        {
            for(int j=p*p;j<=n;j+=p)
            isPrime[j]=false;
        }
    }

    vector<int>prime;

    for(int i=1;i<=n;i++)
    {
        if(isPrime[i])prime.push_back(i);
    }

    return prime;
}

bool isValidArray(int n,vector<int>&vec,vector<int>&primes)
{
   
    unordered_map<int,bool>mp;
    for(auto it:primes)mp[it]=true;

    

    int m=vec.size();

    for(int i=0;i<primes.size();i++)
    {
        int ind=primes[i]-1;
        if(ind>=m)break;

        int ele=vec[ind];

        if(mp.find(ele)==mp.end())return false;
    }

    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++)
    vec.push_back(i+1);

     vector<int>primes=sieve(n);
     cout<<"primes: ";
     for(auto it:primes)cout<<it<<" ";
     cout<<endl;

    int res=0;

    while(next_permutation(vec.begin(),vec.end()))
    {
        if(isValidArray(n,vec,primes)){
            for(auto it:vec)cout<<it<<" ";
            cout<<endl;
            res++;
        }
    }


    return 0;
}