#include<iostream>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int farthestBuilding=0;
        
        int n=heights.size();
        
        for(int i=0;i<n-1;i++)
        {
            int a=heights[i]-heights[i+1];
            //cout<<a<<" ";
            
            if(a>=0)
            {
                farthestBuilding++;
                cout<<"No brick no ladder"<<endl;
            }
           
            else 
            {
                int b=abs(a);
               if(b>bricks && ladders==0)break;
                
               else if(b>bricks)
                {
                    if(ladders>0)
                    {
                        farthestBuilding++;
                        ladders--;
                        cout<<"used ladder"<<endl;
                    }
                }
                else if(ladders==0)
                {
                    if(b<=bricks)
                    {
                        farthestBuilding++;
                        bricks-=b;
                        cout<<"used bricks"<<endl;
                    }
                }
                
                else if(b<=bricks && ladders>0){
                    
                    farthestBuilding++;
                    bricks-=b;
                    cout<<"Both possibillity (bricks)"<<endl;
                }
            }
        }
        return farthestBuilding;
    }
};

int main()
{
    
    return 0;
}