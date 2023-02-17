#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size();

        int start=0;
        int end=0;
        int maxim=INT_MIN;

        unordered_map<int,int>mp;

        while(end<n)
        {
            if(mp.size()<2)
            {
                mp[fruits[end]]=end;
                end++;
               
            }
            else if(mp.size()==2 && mp.find(fruits[end])!=mp.end())
            {
                mp[fruits[end]]=end;
                end++;
               
            }
            else{
                cout<<start<<" "<<end<<endl;
               maxim=max(maxim,end-start);

               int startInd=INT_MAX;
               int reEle;
               for(auto it:mp)
               {
                   if(it.second<startInd)
                   {
                       startInd=it.second;
                       reEle=it.first;
                   }
               }
               mp.erase(reEle);
               start=startInd+1;
            }
           // end++;
        }
        cout<<start<<" "<<end;
        maxim=max(maxim,end-start);

        return maxim;
    }
};

int main()
{
    
    return 0;
}