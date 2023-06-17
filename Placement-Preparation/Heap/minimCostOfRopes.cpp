#include<iostream>
#include<queue>

using namespace std;




// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        if(n==1)return 0;
        
        priority_queue<long long,vector<long long>,greater<long long>>q;
        
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        
        long long ans=0;
        
        while(!q.empty())
        {
            long long firstEle=q.top();
            q.pop();
            long long secondEle=q.top();
            q.pop();
            
            ans+=(firstEle+secondEle);
            q.push(firstEle+secondEle);
            
            if(q.size()==1)break;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

int main()
{
    
    return 0;
}