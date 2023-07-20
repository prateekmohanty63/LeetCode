//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int>res;
        
        sort(candies,candies+N);
        
       
        
        int start=0;
        int end=N-1;
        
        int minCost=0;
        
        while((end-start)>=0)
        {
            minCost+=candies[start];
            start++;
            
           end-=K;
        }
        
        int maxCost=0;
        
        start=0;
        end=N-1;
        
        while((end-start)>=0)
        {
            maxCost+=candies[end];
            end--;
            start+=K;
        }
        
        
        res.push_back(minCost);
        res.push_back(maxCost);
        
        return res;
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends