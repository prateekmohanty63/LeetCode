//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    char intToChar(int a)
   {   
       if(a==0)return '0';
      else  if(a==1)return '1';
       
       else if(a==2)return '2';
       
       else if(a==3)return '3';
       
       else if(a==4)return '4';
       
       else if(a==5)return '5';
       
       else if(a==6)return '6';
       
       else if(a==7)return '7';
       
       else if(a==8)return '8';
       
       else return '9';
   }
     string findSum(string X, string Y) {
        // Your code goes here
        
        int n=X.length();
        int m=Y.length();
        
        int ptr1=n-1;
        int ptr2=m-1;
        
        string res;
        
        char carry='0';
        
        while(ptr1>=0 && ptr2>=0)
        {
            char dig1=X[ptr1];
            char dig2=Y[ptr2];
            
            int num1=int(dig1-'0');
            int num2=int(dig2-'0');
            int currCarry=int(carry-'0');
            
            if((num1+num2+currCarry)<=9)
            {
                res+=intToChar(num1+num2+currCarry);
                carry='0';
            }
            else{
                res+=intToChar((num1+num2+currCarry)%10);
                carry='1';
            }
            
            ptr1--;
            ptr2--;
            
        }
        
        while(ptr1>=0)
        {
            char dig1=X[ptr1];
            int num1=int(dig1-'0');
            int currCarry=int(carry-'0');
            
            if((num1+currCarry)<=9)
            {
                res+=intToChar(num1+currCarry);
                carry='0';
            }
            else{
                res+=intToChar((num1+currCarry)%10);
                carry='1';
            }
            ptr1--;
            
        }
        
        while(ptr2>=0)
        {
            char dig1=Y[ptr2];
            int num1=int(dig1-'0');
            int currCarry=int(carry-'0');
            
            if((num1+currCarry)<=9)
            {
                res+=intToChar(num1+currCarry);
                carry='0';
            }
            else{
                res+=intToChar((num1+currCarry)%10);
                carry='1';
            }
            ptr2--;
        }
        if(carry=='1')res+='1';
        
        reverse(res.begin(),res.end());
        
        string finalRes;
        int k=0;
        
        while(k<res.length())
        {
            if(res[k]!='0')break;
            k++;
        }
        for(int i=k;i<res.length();i++)finalRes+=res[i];
        
        int flag=0;
        for(auto it:res)
        {
            if(it!='0'){
                flag=1;
            }
        }
        
        if(flag==0)return "0";
        
        return finalRes;
    }
    string solve(int arr[], int n) {
        // code here
        
        // sorting the array we get
        sort(arr,arr+n);
        
        string num1,num2;
        
        for(int i=0;i<n;i+=2)
        num1+=intToChar(arr[i]);
        
        for(int i=1;i<n;i+=2)
        num2+=intToChar(arr[i]);
        
        // cout<<num1<<" "<<num2;
        // cout<<endl;
        
        string res=findSum(num1,num2);
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends