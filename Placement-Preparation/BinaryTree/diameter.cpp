
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// T(N)=O(N)
// S(N)=O(N)

pair<int,int> diameterFast(Node* root)
    {
        // base case
        if(!root)
        {  
            // diameter , height
            return {0,0};
        }
        
        pair<int,int>left=diameterFast(root->left);
        pair<int,int>right=diameterFast(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+1+right.second;
        pair<int,int>ans;
        ans.first=max({op1,op2,op3});
        ans.second=max(left.second,right.second)+1;
        
        return ans;
        
    }

// T(N)=O(N^2)
// S(N)=O(N^2)

class Solution {
  public:
  int maxDepth(Node *root)
    {
        // base case
        if(!root)return 0;
        
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        
        return max(leftHeight,rightHeight)+1;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        // base case
        if(!root)return 0;
        
        // diameter of left-subtree
        int left=diameter(root->left);
        int right=diameter(root->right);
        int leftRight=maxDepth(root->left)+1+maxDepth(root->right);
        
        return max({left,right,leftRight});
    }
};


int main()
{
    
    return 0;
}