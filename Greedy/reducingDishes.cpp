#include<iostream>
using namespace std;


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Reducing Dishes

// Greedy approach

// Intution

// 1. We start from the end of the array
// 2. we need to understand that adding an element to the array essentially means value becoming sum of the all the elements + previous answer

// We need to understand the basic concept that if an exra element is taken before the existing array, then the value of answer will increase by the value of element + sum of existing answer. The following example demonstrates this:
// 1 getting added before existing array means that new value = old value + sum of elements

// Hence we need to start from last elemnt taking sum and val both same, then move to last second element and so on. For each element we calculate possible value if the dishes considered start from that index and store the max value seen so far (see code for more clarity)

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n=satisfaction.size();

        sort(satisfaction.begin(),satisfaction.end());

        int sum=satisfaction[n-1];
        int val=satisfaction[n-1];

        int max=sum;

        for(int i=n-2;i>=0;i--)
        {
            sum+=satisfaction[i];
            val+=sum;

            if(val>max)
            max=val;
        }

        if(max<0)return 0;

        return max;
    }
};

// DP solution 

class Solution {
public:

   int maximSatisfication(vector<int>&satisfication,int i,int time,vector<vector<int>>&dp)
   {
       // base case

       if(i>=satisfication.size())return 0;

       if(dp[i][time]!=-1)return dp[i][time];

       // we have the option of either taking the dish or not taking the dish

       return dp[i][time]=max(time*satisfication[i]+maximSatisfication(satisfication,i+1,time+1,dp),maximSatisfication(satisfication,i+1,time,dp));
   }

    int maxSatisfaction(vector<int>& satisfaction) {
        
        // sorting the dishes based on satisfaction level

        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int res=maximSatisfication(satisfaction,0,1,dp);

        return res;


    }
};

int main()
{
    
    return 0;
}

int main()
{
    
    return 0;
}