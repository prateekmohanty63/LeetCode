#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int n=derived.size();
        
        if(n==1 && derived[0]==1)return false;
        
        if(n==1 && derived[0]==0)return true;

       
        vector<int>pos1,pos2;
        
    
        if(derived[0]==0)
        {
            pos1.push_back(0);
            pos1.push_back(0);
            
            pos2.push_back(1);
            pos2.push_back(1);
        }
        
        else if(derived[0]==1)
        {
            pos1.push_back(0);
            pos1.push_back(1);
            
            pos2.push_back(1);
            pos2.push_back(0);
        }
        
        for(int i=1;i<n-1;i++)
        {
           if(derived[i]==0)
           {
              pos1.push_back(pos1[i]);
              pos2.push_back(pos2[i]);
           }
           else{
               // derived is 1
              if(pos1[i]==0)
              {
                pos1.push_back(1);
              }
              else{
                 pos1.push_back(0);
              }
              if(pos2[i]==1)
              {
                  pos2.push_back(0);
              }
              else{
                  pos2.push_back(1);
              }
           }
        }
        
        vector<int>checkVec1,checkVec2;
        
        for(int i=0;i<n-1;i++)
        {
            checkVec1.push_back(pos1[i]^pos1[i+1]);
            checkVec2.push_back(pos2[i]^pos2[i+1]);
        }
        int l=pos1.size();
        int r=pos2.size();
        checkVec1.push_back(pos1[0]^pos1[l-1]);
        checkVec2.push_back(pos2[0]^pos2[r-1]);


        
        if(derived==checkVec1)return true;
        
        if(derived==checkVec2)return true;
        
        return false;
        
    }
};

int main()
{
    
    return 0;
}