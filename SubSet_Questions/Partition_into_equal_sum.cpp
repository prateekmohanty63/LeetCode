#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// correct method
// problem equivalent to 0/1 knapsack

class Solution {
public:
    bool isTrue(vector<int>nums,int targetSum)
    {
        // this question is same as 0/1 knapsack
        
        // making an array of arr[n+1][targetSum+1]
        int n= nums.size();
        int m=targetSum;
        
        
        
      bool vec[n+1][m+1];
        
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                vec[i][j]=false;
            }
        }
        // initilizing the array
        
        vec[0][0] = true;
        
       for(int i=1;i<=n;i++)
       {
           vec[i][0]=true;
       }
        
        for(int i=1;i<=m;i++)
        {
            vec[0][i]=false;
        }
        
        for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < targetSum+1; j++) {
            vec[i][j] = vec[i-1][j];
            if (j >= nums[i-1]) {
                vec[i][j] = (vec[i][j] || vec[i-1][j-nums[i-1]]);
            }
        }
    }
        
        
       
        if(vec[n][m]==1)return true;
        
        return false;
    }
    bool canPartition(vector<int>& nums) {
        
        int  n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        
        if(sum%2!=0)return false;    // array having odd sum cannot be divided into twop equal sums
                                     // suppose sum=s , then s+s =2*s which is even
        
        
        // hence our target sum is half of the array sum
        int targetSum=sum/2;
        
        return isTrue(nums,targetSum);
    }
};

// 1st method ( this is greedy method , will not pass for some test cases)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int start=0,end=nums.size()-1;
        int leftsum=0,rightsum=0;
        
        rightsum=nums[end];
        leftsum=nums[0];
        
        while(start<end)
        {
           
            if(rightsum>leftsum){
                start++;
                 leftsum+=nums[start];
                
            }
            else if(rightsum<leftsum)
            {
                 end--;
                rightsum+=nums[end];
               
            }
            else{
                if(abs(end-start)==1){
                    cout<<start<<" "<<end;
                    return true;
                }
                start++;
                 leftsum+=nums[start];
            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}