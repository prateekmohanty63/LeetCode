
#include<iostream>
#include<vector>

using namespace std;

/// O(N^2) METHOD

int minSubArrayLen(int target, vector<int>& nums) {

        int min=99999;
        int flag=0;
    int n=nums.size();
    for(int i=0;i<nums.size();i++){
        int res=nums[i];
        if(res>=target){
            return 1;
        }
        for(int j=i+1;j<n;j++){
            res+=nums[j];

            if(res>=target){
                if((j-i)+1<=min){
                    min=j-i+1;
                }
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        return 0;
    return min;
}



/// O(N) METHOD
/// 2 pointer approach

int minSubArrayLen1(int target, vector<int>& nums) {


    int sum=0;
    int pointer1=0;
    int res=999999;
        int flag=0;
    int n=nums.size();

    for(int i=0;i<n;i++){
        sum+=nums[i];

        while(sum>=target){
            flag=1;
            sum-=nums[pointer1];
            res=min(res,(i-pointer1)+1);
            pointer1++;

        }
    }
  if(flag==0)
    return 0;
   return res;
    }
}



/// O(N) METHOD   // Testcase failing
int minSubArrayLen2(int target, vector<int>& nums){

   int n;
   n=nums.size();

   vector<int>vec2;
   int sum=0;
   for(int i=0;i<n;i++){
    sum+=nums[i];
   }

   if(target>sum)
    return 0;
   if(sum==target)
    return nums.size();

    vec2.push_back(nums[0]);
    for(int i=1;i<n;i++){
        int r=vec2[i-1]+nums[i];
        vec2.push_back(r);

    }

    int lpointer=0;

    for(int i=0;i<n;i++){
        if(vec2[i]<target)
            lpointer++;
        if(vec2[i]>=target)
            break;
    }

    int min=lpointer+1;
   // int temp=lpointer;
   int sum1=0;

    for(int i=lpointer;i<n-1;i++){
         sum1+=(vec2[i+1]-vec2[i]);

        if(sum1>=target){
            if((i+1)-lpointer<min)
                min=(i+1)-lpointer;
        }
    }

    return min;
}


using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec1;
    for(int i=0;i<n;i++){
        int f;
        cin>>f;
        vec1.push_back(f);
    }

    int target;
    cin>>target;

    int res=minSubArrayLen1(target,vec1);
    cout<<res;

}
