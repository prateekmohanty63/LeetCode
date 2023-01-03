#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>tempArr;
        string res;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            string a=to_string(nums[i]);
            tempArr.push_back(a);
        }

        for(int i=0;i<n-1;i++)
        {
           
            for(int j=0;j<n-i-1;j++)
            {
              string a=tempArr[j];
               string b=tempArr[j+1];
               
               string str1=a+b;
               string str2=b+a;

               if(str1<str2)
               {
                  swap(tempArr[j],tempArr[j+1]);
               }

            }
        }
       
        for(int i=0;i<n;i++){
            res+=tempArr[i];
        cout<<tempArr[i]<<" ";
        }

         int flag=0;

        for(int i=0;i<n;i++)
        {
            if(res[i]!='0')flag=1;
        }
       
       if(flag==0)return "0";

        return res;
    }
};

int main()
{
    
    return 0;
}