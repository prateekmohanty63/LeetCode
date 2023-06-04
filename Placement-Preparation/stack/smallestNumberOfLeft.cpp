#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        
        vector<int>res;
        
        res.push_back(-1);
        
        stack<int>stk;
        // stack 
        stk.push(arr[0]);
        
        for(int i=1;i<n;i++)
        {
            if(stk.top()<arr[i])
            {
                res.push_back(stk.top());
                
            }
            else{
                while(!stk.empty() && stk.top()>=arr[i])stk.pop();
                
                if(stk.empty())res.push_back(-1);
                
                else res.push_back(stk.top());
            }
            stk.push(arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}