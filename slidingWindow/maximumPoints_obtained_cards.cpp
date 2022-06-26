#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// code correct
// though giving memory limit exceeded
class Solution {
public:
    
    int sum(vector<int>vec1,int start,int end)
    {
        int sum1=0;
        for(int i=start;i<=end;i++)
        {
            sum1+=vec1[i];
        }
        return sum1;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int res=0;
        
       
        for(int i=0;i<n;i++)res+=cardPoints[i];
        
        if(n==k)return res;
        
        
        int right=n-k-1,left=0;
        
        int min=INT_MAX;
        
        while(right!=n)
        {
            int sum2=sum(cardPoints,left,right);
            if(sum2<min)min=sum2;
            
            left++;
            right++;
        }
        
        return res-min;
    }
};

int main()
{
    
    return 0;
}