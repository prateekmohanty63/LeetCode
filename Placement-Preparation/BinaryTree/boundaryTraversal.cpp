#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};



// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


void addLeftBoundary(Node *root,vector<int>&res)
{
  
   Node* cur=root->left;
   
   while(cur)
   {
      if(cur->right || cur->left) res.push_back(cur->data);
      
      if(cur->left)cur=cur->left;
      
      else cur=cur->right;
   }
}

void addRightBoundary(Node *root,vector<int>&res)
{
   Node* cur=root->right;
   vector<int>temp;
   
   while(cur)
   {
       if(cur->right || cur->left)temp.push_back(cur->data);
       
       if(cur->right)cur=cur->right;
       
       else cur=cur->left;
   }
   for(int i=temp.size()-1;i>=0;i--)
   {
      res.push_back(temp[i]);
   
   }
}

void addLeaves(Node* root,vector<int>&res)
{
   if(!root)return ;
   
   if(root && !root->left && !root->right)res.push_back(root->data);
   
   addLeaves(root->left,res);
   addLeaves(root->right,res);
   
 
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>res;
        
        if(!root)return res;
        
        if(root->left || root->right)res.push_back(root->data);
        
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        
        return res;
    }
};


int main()
{
    
    return 0;
}