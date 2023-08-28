#include<iostrream>

using namespace std;

/// Approach-1 (TLE)

 vector<int> maxSlidingWindow(vector<int>& nums, int k)
 {
        vector<int>res;
        int n=nums.size();
   for(int i=0;i<n+1-k;i++){
        auto start = nums.begin() + i;
        auto end = nums.begin()+i+k;

         vector<int>result(k);

    // Copy vector using copy function()
      copy(start, end, result.begin());

      sort(result.begin(),result.end());


      res.push_back(result[result.size()-1]);


   }
        return res;
 }

int  main()
{

}
