#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   
    int maximumTastiness(vector<int>& price, int k) {
        
        sort(price.begin(),price.end());
        int n=price.size();
        int start=0;
        int end=price[n-1]-price[0];
        int ans=0;

        while(start<=end)
        {   
            // mid is the candy tastiness value
            int mid=start+(end-start)/2;
            
            int last=0;
            int count=1;
            
            // checking if this mid value difference can be taken for k elements atleast
            for(int i=1;i<n;i++)
            {
                if(price[i]-price[last]>=mid)
                {
                    count++;
                    last=i;
                }
            }
           
           // if it can be taken for k elements , our answer becomes mid 
            if(count>=k)
            {
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return ans;
    }
};

int main()
{
    
    return 0;
}