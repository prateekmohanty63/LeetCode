#include<iostream>
using namespace std;

// 1st method
class Solution {
public:
    void findWinner(int &n,int k,int &count,int &res)
    {
        if(n==1){
            res=count;
            return ;
        }
        
        int temp=k;
        
        while(temp)
        {
            count++;
            if(count>n)
                count=1;
            temp--;
            
        }
        n--;
        findWinner(n,k,count,res);
    }
    int findTheWinner(int n, int k) {
        int count=0;
        int res;
        
        findWinner(n,k,count,res);
        
       if(res==n)return 1;
        return res+1;
    }
};

// 2nd method
// time complexity : O(n)
// space complexity : O(n)
//Runtime: 4 ms, faster than 71.21% of C++ online submissions for Find the Winner of the Circular Game.
//Memory Usage: 5.9 MB, less than 91.71% of C++ online submissions for Find the Winner of the Circular Game.

class Solution {
public:
    int winner(int n,int k)
    {
        if(n==1)return 0;
        
        return (winner(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        
        int a=winner(n,k)+1;
        
        return a;
    }
};

// iterative method
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Winner of the Circular Game.
//Memory Usage: 5.8 MB, less than 91.71% of C++ online submissions for Find the Winner of the Circular Game.

class Solution {
public:
    
    int winner(int n,int k)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
           ans=(ans+k)%i; 
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        int res=winner(n,k);
        
        return res+1;
    }
};

int main()
{
    
    return 0;
}