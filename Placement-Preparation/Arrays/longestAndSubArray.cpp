#include<iostream>
using namespace std;


#include <iostream>
#include<climits>

using namespace std;

#include <iostream>
#include<climits>
#include<cmath>

using namespace std;

// T(N)=O(log2(n))
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int ans;
	    
	    int m=log2(n);
	    int a = (n - pow(2,(m))) + 1;
        int b = (pow(2,(m))/2);
	   
	    
	    ans=max(a,b);
   
	    cout<<ans<<endl;
	}
	return 0;
}


// TLE (as n is 1e9)
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    
	    int start=1;
	    int end=1;
	    int ans=INT_MIN;
	    int currEle=1;
	    
	    while(end<=n)
	    {
	        currEle=currEle&end;
	        if(currEle!=0)
	        {
	            ans=max(ans,end-start+1);
	        }
	        else{
	            start=end;
	            currEle=start;
	        }
	        end++;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}


int main()
{
    
    return 0;
}