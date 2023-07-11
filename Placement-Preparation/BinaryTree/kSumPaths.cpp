//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// T(N)=O(N)
// S(N)=O(H)
class Solution{
  public:
  
   void solve(Node *root,int &k,int &count,unordered_map<int,int>&mp,int sum)
   {
       // base case
       if(!root)return ;
       
       sum+=root->data;
       
       count+=mp[sum-k];
       if(sum==k)count++;
       
       mp[sum]++;
       
       solve(root->left,k,count,mp,sum);
       solve(root->right,k,count,mp,sum);
       
       mp[sum]--;
   }
    int sumK(Node *root,int k)
    {
        // code here 
      unordered_map<int,int>path;
        int res=0;
        solve(root,k,res,path,0);
        
        return res;
    
    }
};


struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// T(N)=O(N^2)
// S(N)=O(H)
class Solution{
  public:
    void solve(Node* root,int &k,int sum,int &count)
    {
        // base case
         if(sum==k)count++;
         if(!root)return ;
         
         solve(root->left,k,sum+root->data,count);
         solve(root->right,k,sum+root->data,count);
    }
    void treeTraverse(Node* root,int k,int &count)
    {
        // base case
        if(!root)return ;
        
        solve(root,k,0,count);
        
        treeTraverse(root->left,k,count);
        treeTraverse(root->right,k,count);
    }
    int sumK(Node *root,int k)
    {
        // code here 
        int res=0;
         treeTraverse(root,k,res);
         return res/2;
    }
};

