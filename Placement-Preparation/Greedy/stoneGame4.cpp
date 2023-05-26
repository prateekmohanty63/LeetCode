#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;


class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        int temp=n;
        int alicePoints=0;
        int bobPoints=0;
        int turn=0;

       
        vector<pair<int,vector<int>>>vec;
        priority_queue<pair<int,vector<int>>>q;
        for(int i=0;i<aliceValues.size();i++)
        {
            
            pair<int,vector<int>>pr;
            vector<int>vec1;
            pr.first=aliceValues[i]+bobValues[i];
            vec1.push_back(aliceValues[i]);
            vec1.push_back(bobValues[i]);
            pr.second=vec1;
            q.push(pr);
            
        }
       
      
       while(!q.empty())
       {
           pair<int,vector<int>>pr=q.top();
           q.pop();

           if(turn%2==0)
           {
               alicePoints+=pr.second[0];
           }
           else{
               bobPoints+=pr.second[1];
           }
           turn++;
       }
        

       
        cout<<alicePoints<<" "<<bobPoints<<endl;

        if(alicePoints==bobPoints)return 0;

        if(alicePoints>bobPoints)return 1;

        return -1;
    }
};

// TLE 
// T(N)=O(n^2)
// S(N)=O(1)

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        int temp=n;
        int alicePoints=0;
        int bobPoints=0;
        int turn=0;

        while(temp!=0)
        {
           if(turn%2==0)
           {
                // alice's turn
                int maxim=INT_MIN;
                int ind=-1;
                for(int i=0;i<aliceValues.size();i++)
                {
                    if(aliceValues[i]+bobValues[i]>maxim)
                    {
                        maxim=aliceValues[i]+bobValues[i];
                        ind=i;
                    }
                }
                alicePoints+=aliceValues[ind];
                aliceValues[ind]=0;
                bobValues[ind]=0;
           }
           else{
               // bob's turn
               int maxim=INT_MIN;
                int ind=-1;
                for(int i=0;i<bobValues.size();i++)
                {
                    if(bobValues[i]+aliceValues[i]>maxim)
                    {
                        maxim=bobValues[i]+aliceValues[i];
                        ind=i;
                    }
                }
                bobPoints+=bobValues[ind];
                aliceValues[ind]=0;
                bobValues[ind]=0;
           }
           turn++;
           temp--;
        }

        cout<<alicePoints<<" "<<bobPoints<<endl;

        if(alicePoints==bobPoints)return 0;

        if(alicePoints>bobPoints)return 1;

        return -1;
    }
};

int main()
{
    
    return 0;
}