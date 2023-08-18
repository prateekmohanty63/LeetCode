//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// T(N)=O(N)

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       
        int balance=0;
        int deficite=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            balance+=p[i].petrol-p[i].distance;
            if(balance<0)
            {
                ans=i+1;
                deficite+=balance;
                balance=0;
            }
            
        }
        if(balance+deficite>=0)return ans;
        
        return -1;
       
    }
};


// T(N)=O(N^2)


struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
  bool isPossible(petrolPump p[],int n,int &start,int ind,int PetrolLeft)
  {
       if(ind%n==start)return true;
       
       int petrolTaken=PetrolLeft+p[ind%n].petrol-p[ind%n].distance;
       
       if(petrolTaken>=0)
       return isPossible(p,n,start,(ind+1)%n,petrolTaken);
       
       else return false;
  }
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here 
       int currentPetrol=0;
       int nextDistance=0;
       
       
       for(int i=0;i<n;i++)
       {
          currentPetrol=p[i].petrol;
          nextDistance=p[i].distance;
          
          if(currentPetrol<nextDistance)continue;
          
          else{
              // possible starting point
              if(isPossible(p,n,i,(i+1)%n,currentPetrol-nextDistance))
              return i;
          }
       }
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{

}

// } Driver Code Ends