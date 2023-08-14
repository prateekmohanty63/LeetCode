
/// Appraoch-1

/// Passing only 109 test cases out of 318 test cases

/// 0(n^2logn)

class Solution {

    int binarySearch(vector<int>nums,int l,int r,int target){

        if(r>=l){
        int mid=l+(r-l)/2;

        if(nums[mid]==target)return mid;

        if(target<nums[mid])
           return binarySearch(nums,l,mid-1,target);
        if(target>nums[mid])
           return binarySearch(nums,mid+1,r,target);
        }

        return -1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;

        if(nums.size()<3)return res;

         vector<vector<int>>::iterator itr;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 vector<int>vec1;

                int sum=nums[i]+nums[j];
                int target=0-sum;

                int index=binarySearch(nums,0,nums.size()-1,target);
                if(index!=-1){
                    vec1.push_back(nums[i]);
                    vec1.push_back(nums[j]);
                    vec1.push_back(nums[index]);
                    sort(vec1.begin(),vec1.end());

                     itr= find(res.begin(),res.end(),vec1);
                    if(itr!=res.end())
                        continue;
                    else{
                        if(i!=j && i!=index && j!=index)
                    res.push_back(vec1);
                    }
                }
            }
        }

       return res;
    }
};

/// Approach-2
/// 2 pointer approach
/// O(n^2)
/// best time complexity for this question


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>res;

        int n;

        n=nums.size();

        if(n<3) return res;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){

            if(i==0 || (i>0 && nums[i]!=nums[i-1])){

                int l=i+1,r=nums.size()-1,sum=0-nums[i];

                while(l<r){
                     vector<int>vec1;
                    if(nums[l]+nums[r]==sum){
                        vec1.push_back(nums[i]);
                        vec1.push_back(nums[l]);
                        vec1.push_back(nums[r]);
                        res.push_back(vec1);

                        while(l<r && nums[l]==nums[l+1])l++;
                        while(l<r && nums[r]==nums[r-1])r--;

                        l++;
                        r--;
                    }
                    else if(nums[l]+nums[r]<sum)
                        l++;
                    else
                        r--;

                }
            }
        }
        return res;
    }
};

