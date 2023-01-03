#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    static bool cmp(int a,int b)
    {
       int i=0,j=0;
       string str=to_string(a);
       string str1=to_string(b);

       while(i<str.length() && j<str1.length())
       {
           if(str[i]==str1[j])i++,j++;

           else break;
       }

       if(i<str.length() && j<str1.length())
       {
           return str[i]>str1[j];
       }

       return str+str1>str1+str;
    }

    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),cmp);

         if(count(nums.begin(), nums.end(), 0) == nums.size()) 
            return "0";

            string res;

            for(auto it:nums)
            {
                res+=to_string(it);
            }
            return res;
    }
};


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