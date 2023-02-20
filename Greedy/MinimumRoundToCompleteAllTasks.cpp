#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int n=tasks.size();
        int count=0;

        unordered_map<int,int>mp;

        for(auto it:tasks)
        {
            mp[it]++;
        }


        // if there is a task occuring less than twice
        for(auto it:mp)
        {
            if(it.second<2)return -1;
        }

        for(auto it:mp)
        {
            int a=it.second;

            // if the task is divisible by 3 , increase the count by a/3;
            if(a%3==0)count+=(a/3);
            
            else{
                int cnt=0;
                int temp=a;
                int start=a/3;
                int flag=0;
               
                for(int i=start;i>=1;i--)
                {
                    int r=temp-3*i;

                    if(r%2==0)
                    {
                        cnt=i;
                        flag=1;
                        break;
                    }
                }

                if(flag==1)
                {
                    int twoDiv=a-3*cnt;
                    count+= (cnt + (twoDiv)/2);
                }
                else{
                    count+=(temp/2);
                }
               
            }

        }
       
       return count;

    }
};

int main()
{
    
    return 0;
}