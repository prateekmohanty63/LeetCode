#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n=customers.size();

        int curr=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)curr+=customers[i];
        }
        int res=curr;

        int maxim=INT_MIN;
        int sum=0;

        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)sum+=customers[i];
        }
        maxim=max(maxim,sum);
       
        int start=0;
        int end=minutes;

        while(end<n)
        {
            if(grumpy[start]==1)sum-=customers[start];
            if(grumpy[end]==1)sum+=customers[end];
            
            maxim=max(maxim,sum);
            start++;
            end++;
        }
       
       return res+maxim;
    }
};

int main()
{
    
    return 0;
}