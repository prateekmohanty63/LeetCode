#include<iostream>
#include<vector>
using namespace std;

// recursive approach

class Solution {
public:
    int solve(int n,int k)
    {
        // base case
        if(n==1)return 0;

        return (solve(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        
        return solve(n,k)+1;
    }
};



// iteratrive approach

// Function for finding the winning child.
long long int find(long long int n, long long int k)
{
    long long int sum = 0, i;
 
    // For finding out the removed
    // chairs in each iteration
    for (i = 2; i <= n; i++)
        sum = (sum + k) % i;
 
    return sum + 1;
}

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