#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    long long smallestNumber(long long num) {
        
        long long res;

        if(num==0)return 0;
        
        string a=to_string(num);

        vector<char>vec;

        for(auto it:a)
        {
            if(it!='-'){
              
                vec.push_back(it);
           
            }
        }

        sort(vec.begin(),vec.end());

       // for(auto it:vec)cout<<it<<" ";

        int n=vec.size();

        if(num>0)
        {
           string temp;
           
           int zeroCount=0;

           int k=0;

           while(k<n && vec[k]=='0')
           {
               k++;
           }

           temp+=vec[k];

           for(int i=0;i<k;i++)temp+='0';

           for(int i=k+1;i<n;i++)temp+=vec[i];

           cout<<temp;
           res=stoll(temp);
        }
        else{

            string temp;

            for(int i=n-1;i>=0;i--)
            temp+=vec[i];

            res=stoll(temp);
            res=res*-1;
        }
        
       
        return res;
    }
};

int main()
{
    
    return 0;
}