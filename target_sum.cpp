class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        vector<int>res;

        int tar=numbers[l]+numbers[r];
        if(tar==target){
            res.push_back(l+1);
            res.push_back(r+1);
        }
        while(tar!=target){
            tar=numbers[l]+numbers[r];
            if(tar<target){
                l++;
            }
            else if(tar>target){
                r--;
            }
            else{
                res.push_back(l+1);
                res.push_back(r+1);
            }
        }
         return res;
    }
};
