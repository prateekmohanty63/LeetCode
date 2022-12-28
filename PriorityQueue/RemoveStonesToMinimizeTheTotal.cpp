#include<iostream>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

         int minStonesLeft=0;
        int n=piles.size();
        
      priority_queue<int>q;
      for(int i=0;i<piles.size();i++)
      {
           q.push(piles[i]);
      }

       

        while(k!=0)
        {
           int maxim=q.top();
           int stonesToRemove=maxim/2;
           maxim-=stonesToRemove;
           q.pop();
           q.push(maxim);
          
           k--;
        }

        while(!q.empty())
        {
            minStonesLeft+=q.top();
            q.pop();
        }

        return minStonesLeft;
    }
};

int main()
{
    
    return 0;
}