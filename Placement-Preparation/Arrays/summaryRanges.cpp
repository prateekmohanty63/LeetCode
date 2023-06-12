#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string>res;

        int n=nums.size();

        int k=0;

        while(k<n)
        {    
            int start=nums[k],end;
            int flag=0;
            if(k+1<n && nums[k+1]-1==nums[k]){   
                flag=1;  
                start=nums[k];           
                while(k+1<n && nums[k+1]-1==nums[k])k++;
                end=nums[k];
            }
            if(flag==1){
                string a=to_string(start)+"->"+to_string(end);
                res.push_back(a);
            }
            else{
                res.push_back(to_string(start));
            }
            k++;
            
        }
        return res;
    }
};

int main()
{
    
    return 0;
}