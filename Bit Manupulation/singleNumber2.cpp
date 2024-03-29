#include<iostream>
#include<vector>
#include<climits>

using namespace std;


// Bit manipulation method
// Time complexity: O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // ones store all the elements occuring 1 time in the array
        int ones=0;

        // twos store all the element occuring 2 times in the array
        int twos=0;

        for(auto it:nums)
        {
            ones=(ones^it)&(~twos);
            twos=(twos^it)&(~ones);
        }

        return ones;
    }
};

// Bit manipulation method
// Time complexity: O(n*32)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        long long shift=1;

        double ans=0;
        int n=nums.size();
        

        int numNeg=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)numNeg++;
          
        }
        
        for(int i=0;i<32;i++)
        {
            long long numberOfSetBits=0;
            for(int j=0;j<n;j++)
            {
                numberOfSetBits+=(abs(nums[j])&shift);
            }
            cout<<numberOfSetBits<<" ";
            if(numberOfSetBits%3!=0)
            ans+=(shift);

            shift=shift<<1;
        }

       //cout<<numNeg;
      if(numNeg%3==0)
      return ans;
   //  cout<<" "<<ans;
      return 0-ans;
    }
};

int main()
{
    
    return 0;
}