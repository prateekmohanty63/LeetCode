//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    vector<long long>res;
    vector<int>negInd;
    
    int start=0;
    int end=K-1;
    
    
    for(int i=start;i<=end;i++)
    {
        if(A[i]<0)
        {
            negInd.push_back(i);
        }
    }
    
    int l=0;
    if(negInd.size()==0)
    res.push_back(0);
    
    else res.push_back(A[negInd[l]]);
    start++;
    end++;
    
    while(end<N)
    {
     
        if(end<N && A[end]<0)negInd.push_back(end);
        
        if(negInd.size()==0)
        {
            res.push_back(0);
        }
        else{
        while(l<negInd.size() && negInd[l]<start)l++;
        
        if(l<negInd.size()){
        if(negInd[l]>=start && negInd[l]<=end)
        {
            res.push_back(A[negInd[l]]);
        }
        else res.push_back(0);
        }
        else{
            res.push_back(0);
        }
    }
     start++;
        end++;
 }
 return res;
}
 