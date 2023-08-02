#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        
        vector<string>vec;

        int n=nums.size();

        for(auto it:nums)
        {
            string a=to_string(it);
            vec.push_back(a);
        }

        for(int i=0;i<n;i++)
        {
            string a=vec[i];
            reverse(a.begin(),a.end());
            int k=0;
            string b;
            while(k<n && a[k]=='0')k++;

            for(int j=k;j<a.length();j++)b+=a[j];
           
           if(b.length()>0)
            vec.push_back(b);
        }

        unordered_map<string,bool>mp;

        for(auto it:vec)mp[it]=true;

        return mp.size();
    }
};

int main()
{
    
    return 0;
}