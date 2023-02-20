#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int res=0;

        int sum1=0,sum2=0;

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)sum1+=nums1[i];

        for(int i=0;i<m;i++)sum2+=nums2[i];

        if(sum1==sum2)return res;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());


        
       

     //   if(sum1>m*6 || sum2>n*6)return -1;

       if(sum1>sum2)
       {
            int diff=(sum1-sum2);
            int k=n-1;
            int l=0;

            while(sum1>sum2)
            {
                int firstDec;
                 int secInc;

              if(k>=0)
               firstDec=nums1[k]-1;

               else firstDec=INT_MIN;

               if(l<m)
                secInc=6-nums2[l];

                else secInc=INT_MIN;

               if(firstDec>secInc)
               {
                   sum1-=firstDec;
                   res++;
                   k--;
               }
               else{
                   sum2+=secInc;
                   res++;
                   l++;
               }

               if(k<0 && l>=m)break;
            }

           if(sum1>sum2)return -1;
       } 
       else{

           int diff=(sum2-sum1);
           int k=m-1;
           int l=0;
          
          while(sum2>sum1){

            int secDec,firstInc;
            
            if(k>=0)
           secDec=nums2[k]-1;

           else secDec=INT_MIN;

           if(l<n)
           firstInc=6-nums1[l];

           else firstInc=INT_MIN;
           
             if(secDec>firstInc)
             {
                 sum2-=secDec;
                 res++;
                 k--;

             }
             else{
                 sum1+=firstInc;
                 res++;
                 l++;
             }

             if(k<0 && l>=n)break;
              
          }

          if(sum2>sum1)return -1;

       }
     
       return res;
    }
};

int main()
{
    
    return 0;
}