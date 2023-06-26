#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// T(N)=O(k*(log(candidates)))
// S(N)=O(2*candidates)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res=0;

        int n=costs.size();

        priority_queue<pair<int,pair<int,string>>,vector<pair<int,pair<int,string>>>,greater<pair<int,pair<int,string>>>>pq;
        
        int start=0;
        int end=n-1;

        for(start=0;start<candidates;start++)
        {
            pq.push({costs[start],{start,"start"}});
        }
        int temp=candidates;

        while(end>start && temp!=0)
        {
            pq.push({costs[end],{end,"end"}});
            end--;
            temp--;
        }
        start--;
        end++;
        cout<<start<<" "<<end<<endl;

        while(k!=0)                         // O(K)
        {
            pair<int,pair<int,string>>tp=pq.top();
            pq.pop();                       // O(log(candidates))
            int val=tp.first;
            int index=tp.second.first;
            string str=tp.second.second;
            
          //  cout<<val<<" "<<index<<" "<<str<<endl;

            if(end-start>=1)
            {
                res+=(long long)val;

                if(str=="start")
                {
                    if(start+1!=end){
                    start++;
                    pq.push({costs[start],{start,"start"}});
                    }
                    
                }
                else{
                   
                   if(end-1!=start){
                    end--;
                    pq.push({costs[end],{end,"end"}});       // O(log(candidates))
                   }
                    
                }
            }
            else{
                res+=(long long)val;
            }
            k--;
        }
       
        return res;
    }
};

int main()
{
    
    return 0;
}