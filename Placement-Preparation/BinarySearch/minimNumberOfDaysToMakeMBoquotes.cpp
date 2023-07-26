#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int start=1;
        int end=1000000000;
        int res=INT_MAX;
        int n=bloomDay.size();
        int maxDay=INT_MIN;
       

        for(auto it:bloomDay)maxDay=max(maxDay,it);
        
        long long int prod=(long long)m*k;
        if(prod>n)return -1;
    

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int boqFormed=0;
            int currCount=0;
            
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid)
                {
                    currCount++;

                    if(i==n-1)
                    {
                        boqFormed+=(currCount/k);
                    }
                }
                else{
                     boqFormed+=(currCount/k);
                     currCount=0;
                }
            }
            
            int s=0;
            int e=k-1;

           
            if(boqFormed>=m)
            {
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }


        }


        return res;
    }
};

int main()
{
    
    return 0;
}