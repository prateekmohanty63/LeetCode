#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        
        int count=0;
        vector<int>circle(n,1);
        
    
        int i=0;

        while(count!=n-1)
        {

            int temp=k;

            while(temp!=0)
            {
                i=(i+1)%(n);

                if(circle[i%n]==1)
                temp--;
            }
            while(circle[i]!=1)
            {
               i=(i+1)%(n);
            }
            circle[i]=0;
             count++;
           
        }
        
        int ans;
        for(int i=0;i<n;i++)
        {
           // cout<<circle[i]<<" ";
            if(circle[i]==1)ans=i;
        }
        if(ans==0)return n;
        return ans;
    }
};

int main()
{
    
    return 0;
}