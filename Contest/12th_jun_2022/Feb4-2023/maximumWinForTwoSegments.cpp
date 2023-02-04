#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        
        unordered_map<int,int>freq;
        vector<int>maxIntervals;
        int res=0;
        
        for(auto it:prizePositions)
        {
            freq[it]++;
        }
         
        int n=prizePositions.size();
        int maxNum=prizePositions[n-1];
       
        
      int startPtr=prizePositions[0];
      int endPtr=startPtr+k;
        
    
   
        
     int currSum=0;
        
        for(int i=startPtr;i<=endPtr;i++)
        {
            if(freq.find(i)!=freq.end())currSum+=freq[i];
        }
        
        maxIntervals.push_back(currSum);
        
        startPtr=endPtr+1;
        endPtr=startPtr+k;
        currSum=0;
        
        while(startPtr<=maxNum)
        {
           
            for(int i=startPtr;i<=endPtr;i++)
            {
                if(freq.find(i)!=freq.end())currSum+=freq[i];
            }
            
             cout<<startPtr<<" "<<endPtr<<endl;
            
            startPtr=endPtr+1;
            endPtr=startPtr+k;
            
           
            
            maxIntervals.push_back(currSum);
             currSum=0;
            
        }
        
        cout<<endl;
        
          int max1=-1;
        int max2=-1;
        int max1Pos=-1;
        
        
        for(int i=0;i<maxIntervals.size();i++)
        {
            if(maxIntervals[i]>max1)
            {
                max1=maxIntervals[i];
                max1Pos=i;
            }
        }
        
        for(int i=0;i<maxIntervals.size();i++)
        {
            if(i!=max1Pos && maxIntervals[i]>=max2)
            {
                max2=maxIntervals[i];
                
            }
        }
        
        
      // sort(maxIntervals.begin(),maxIntervals.end(),greater<int>());
        
       
        
        
        
        return maxIntervals[0]+maxIntervals[1];
       
    }
};

int main()
{
    
    return 0;
}