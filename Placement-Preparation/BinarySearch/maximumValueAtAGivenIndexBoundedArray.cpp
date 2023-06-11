#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  
  typedef long long ll;

  ll getSumByFormula(ll count,ll x)
  {
      return (count*x)-(count*(count+1))/2;
  }

    int maxValue(int n, int index, int maxSum) {
        
        ll left=1;
        ll right=maxSum;

        ll mid_val;

        int result=0;

        while(left<=right){
            mid_val=left+(right-left)/2;



        // left

            ll left_count=min((ll)index,mid_val-1);

            ll left_sum=getSumByFormula(left_count,mid_val);

            left_sum+=max((ll)0,index-mid_val+1);    // extra ones if any


       // right

            ll right_count=min((ll)n-index-1,mid_val-1);

            ll right_sum=getSumByFormula(right_count,mid_val);

              right_sum += max((ll)0, n-index-1 - mid_val+1);   // extra ones if any
           
           ll totalSum=left_sum+mid_val+right_sum;

           if(totalSum<=maxSum)
           {
               result=max((ll)result,mid_val);
               left=mid_val+1;
           }
           else{
               right=mid_val-1;
           }
        }
        return result;
    }
};

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        vector<int>vec(n,0);

        for(int i=maxSum;i>=1;i--)
        {
            vec[index]=i;

            // set all number previous to index as curr-1

            for(int j=index-1;j>=0;j--)
            {  
                if(vec[j+1]-1!=0)
                vec[j]=vec[j+1]-1;
            }

            // set all number aftet index as curr-1
            for(int j=index+1;j<n;j++){
                if(vec[j-1]-1!=0)
                vec[j]=vec[j-1]-1;
            }

            int totalSum=0;
            for(int j=0;j<n;j++)totalSum+=vec[j];

            if(totalSum<=maxSum)return vec[index];
        }

        return vec[index];
    }
};

int main()
{
    
    return 0;
}