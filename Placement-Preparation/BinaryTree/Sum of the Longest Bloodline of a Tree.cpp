
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// T(N)=O(N)
// S(N)=O(H)

class Solution
{
public:
  int longestPath=INT_MIN;
  int res=0;
   void maxSum(Node *root,int count,int sum)
   {
       // base case
       if(!root)
       {
           if(count>longestPath)
           {
               longestPath=count;
               res=sum;
           }
           else if(count==longestPath)
           {
               res=max(res,sum);
           }
           return ;
       }
       maxSum(root->left,count+1,sum+root->data);
       maxSum(root->right,count+1,sum+root->data);
   }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        maxSum(root,0,0);
        
        return res;
    }
};

//{ Driver Code Starts.



int main()
{
    
    return 0;
}