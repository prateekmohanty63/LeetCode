#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        
        // initially all the indexes are un-colored
        vector<int>colorArray(n,0);
        vector<int>res;
        int m=queries.size();
        
        int sameInit=0;
        
        for(int i=0;i<m;i++)
        {   
            int ind=queries[i][0];
            int color=queries[i][1];
            
            if(colorArray[ind]!=0)
            {
                if(ind-1>=0 && colorArray[ind]==colorArray[ind-1] && color!=colorArray[ind-1])sameInit--;
                
                if(ind+1<n && colorArray[ind]==colorArray[ind+1] && color!=colorArray[ind+1])sameInit--;
                
                
                
                 if(colorArray[ind]!=color){
                     colorArray[ind]=color;
                  // cout<<"IN"<<" ";
                  colorArray[ind]=color;
                    
                    if(ind+1<n && colorArray[ind]==colorArray[ind+1])sameInit++;
                    
                    if(ind-1>=0 && colorArray[ind]==colorArray[ind-1])sameInit++;
                    
                   cout<<sameInit<<" ";
                 
                }
            }
            else{
                
               if(colorArray[ind]!=color){
                  // cout<<"IN"<<" ";
                  colorArray[ind]=color;
                    
                    if(ind+1<n && colorArray[ind]==colorArray[ind+1])sameInit++;
                    
                    if(ind-1>=0 && colorArray[ind]==colorArray[ind-1])sameInit++;
                    
                   cout<<sameInit<<" ";
                 
                }
            }
           
              res.push_back(sameInit);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}