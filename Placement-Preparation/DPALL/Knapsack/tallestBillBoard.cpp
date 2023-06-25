#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// T(N)=O(3^n)
// S(N)=O(N)

class Solution {
public:
    int solve(vector<int>&rods,int index,int rod1,int rod2 )
    {
        // base case
        int n=rods.size();
        int ans=INT_MIN;

        if(rod1==rod2){
            cout<<rod1<<" "<<rod2<<endl;
            ans=max(ans,rod1);
        }

        if(index>=n)return ans;

        
       ans=max(ans,solve(rods,index+1,rod1+rods[index],rod2));
       ans=max(ans,solve(rods,index+1,rod1,rod2+rods[index]));
       ans=max(ans,solve(rods,index+1,rod1,rod2));

       return ans; 


    }
    int tallestBillboard(vector<int>& rods) {
        
        int n=rods.size();

       
        int res=solve(rods,0,0,0);

        return res;


    }
};

int main()
{
    
    return 0;
}