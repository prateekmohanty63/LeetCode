
class Solution {
    vector<vector<int>>res;
    void generate(vector<int>&subset,int i,vector<int>&nums){

        if(i==nums.size())
        {
            res.push_back(subset);
            return ;
        }
        generate(subset,i+1,nums);

        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        subset.pop_back();
    }

int xorOfArray(vector<int>arr, int n)
{
    // Resultant variable
    int xor_arr = 0;

    // Iterating through every element in
    // the array
    for (int i = 0; i < n; i++) {

        // Find XOR with the result
        xor_arr = xor_arr ^ arr[i];
    }

    // Return the XOR
    return xor_arr;
}

public:
    int subsetXORSum(vector<int>& nums) {
        vector<int>vec1;
        generate(vec1,0,nums);

        int sum1=0;

        for(int i=0;i<res.size();i++){
            int sum=0;
            vector<int>vec2;
            vec2=res[i];
            sum=xorOfArray(vec2,vec2.size());
            sum1+=sum;


        }
   return sum1;
    }
};
