#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Successful Pairs of Spells and Potions


// Time complexity: O(nlogn)

class Solution {
public:
  
  int binarySearch(vector<int>&potions,int spell,long long success,int start,int end,int index)
  {
      if(start<=end)
      {
          int mid=start+(end-start)/2;
         // long long cmp=potions[mid]*spell;

          if((long long)potions[mid]*spell>=success)
          {
            return binarySearch(potions,spell,success,start,mid-1,mid);
          }
          else{
              return binarySearch(potions,spell,success,mid+1,end,index);
          }


      }
      return index;
  }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int>vec;
        sort(potions.begin(),potions.end());

        for(int i=0;i<spells.size();i++)
        { 
            int target=success;
            int ans=binarySearch(potions,spells[i],success,0,potions.size()-1,-1);
            cout<<ans<<" ";

            if(ans==-1)vec.push_back(0);

            else 
            vec.push_back(potions.size()-(ans));
        }


        return vec;
    }
};

int main()
{
    
    return 0;
}