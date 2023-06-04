#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>res;
       res.push_back(1);
       
       stack<int>stk;
       
       // pass the index into the stack
       stk.push(0);
       
       // idea is about finding the first greater element towards the left 
       
       for(int i=1;i<n;i++)
       {
            int currInd=stk.top();
            
            if(price[currInd]>price[i])
            {
                res.push_back(i-stk.top());
            }
            else{
                while(!stk.empty() && price[stk.top()]<=price[i])stk.pop();
                
                if(stk.empty())res.push_back(i+1);
                
                else res.push_back(i-stk.top());
            }
            stk.push(i);
       }
       return res;
       
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends

int main()
{
    
    return 0;
}