#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// T(N)=O(n)
// S(N)=O(1)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        int res=1;

        int start=0;
        int end=0;
        int n=nums.size();
        long long total=0;

        while(end<n)
        {
           int winLength=end-start+1;
           total+=nums[end];
           long long sumReq=(long long)((long long)nums[end]*(long long)winLength)-k;

           if(sumReq<=total)
           {
               res=max(res,winLength);
           }
           else{
               int len=end-start+1;
               long long currReq=(long long)((long long)nums[end]*(long long)len)-k;
            // nums[end]*len>total+k

               while(start<=end && currReq>total){
                   
                   total-=nums[start];
                   start++;
                   len--;
                   currReq=(long long)((long long)nums[end]*(long long)len)-k;
               }
               res=max(res,end-start+1);
           }
            end++;
        }
        return res;
    }
};


// T(N)=O(N^2)
// S(N)=O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        // sorting the nums
        sort(nums.begin(),nums.end());

        int res=1;
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            int count=1;
            int ele=nums[i];
            int tempK=k;

            for(int j=i-1;j>=0;j--)
            {
                if(ele-nums[j]<=tempK){
                    count++;
                    tempK-=(ele-nums[j]);
                }
                else break;
            }
            res=max(res,count);
        }
       return res;
    }
};

int main()
{
    
    return 0;
}