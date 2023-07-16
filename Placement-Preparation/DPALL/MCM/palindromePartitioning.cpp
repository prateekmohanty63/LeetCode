#include<iostream>
#include<climits>
using namespace std;

class Solution{
public:
    bool isPalindrome(string str,int i,int j)
    {
        while(i<=j)
        {
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string str,int i,int j)
    {
        // base case
        // if string is of size 0 or 1 , we dont need to do any partitions
        if(i>=j)return 0;
        
        if(isPalindrome(str,i,j))return 0;
        
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            
           // here +1 refers to that we have done 1 partition
            int tempAns=1+solve(str,i,k)+solve(str,k+1,j);
            ans=min(ans,tempAns);
        }
        return ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        
        int res=solve(str,0,n-1);
        
        return res;
        
        
    }
};

int main()
{
    
    return 0;
}