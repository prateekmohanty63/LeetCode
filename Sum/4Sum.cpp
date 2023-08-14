class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>>res;
        
        if(n<4)return res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++){
            
            for(int j=i+1;j<n-2;j++){
                vector<int>vec1;
                int a=target-(nums[i]+nums[j]);
                
                int left=j+1,right=nums.size()-1;
               
                while(left<right){
                    if(nums[left]+nums[right]==a){
                        vec1.push_back(nums[i]);
                        vec1.push_back(nums[j]);
                        vec1.push_back(nums[left]);
                        vec1.push_back(nums[right]);
                        sort(vec1.begin(),vec1.end());
                        res.push_back(vec1);
                        
                        while(left<right && nums[left]==nums[2])left++;
                        while(left<right && nums[right]==nums[3])right--;
                        
                        left++,right--;
                    }
                    else if(nums[left]+nums[right]<a){
                        left++;
                    }
                    else{
                        right++;
                    }
                }
                
                while(j+1<nums.size() && nums[j]==nums[j+1])j++;
            }
              while(i+1<nums.size() && nums[i]==nums[i+1])i++;
        }
        return res;
    }
};


/// Approach -2

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    
        vector<vector<int> > res;
    
        if (num.empty())
            return res;
    
        std::sort(num.begin(),num.end());
    
        for (int i = 0; i < num.size(); i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < num.size(); j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = num.size() - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    
    }
};