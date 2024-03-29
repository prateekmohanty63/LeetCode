#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int j=num.size()-1;

        while(j>=0)
        {
            int sum=num[j]+carry+k%10;
            k/=10;

            num[j--]=sum%10;
            carry=sum/10;
        }

        while(k>0)
        {
            int sum=(k%10)+carry;
            k/=10;
            num.insert(num.begin(),sum%10);
            carry=sum/10;
        }

        if(carry>0)
        {
            num.insert(num.begin(),carry);
        }

      return num;
    }
};

// Giving precision error
// going out of long long , because array is of size 10^4

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        long long res=0;
        vector<int>vec;

        int n=num.size();
        int l=1;

        for(int i=0;i<n;i++)
        {
            res+=num[i]*pow(10,n-l);
            l++;
        }

        res+=k;

        string sum=to_string(res);

        for(int i=0;i<sum.length();i++)
        {
            char a=sum[i];
            int r=int(a)-48;
            vec.push_back(r);
        }

        cout<<res;

        return vec;
    }
};

int main()
{
    
    return 0;
}