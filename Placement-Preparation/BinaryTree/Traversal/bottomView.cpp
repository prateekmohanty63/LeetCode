#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;


#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> solve(Node *root)
    {
        vector<int>res;
        if(!root)return res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        
        while(!q.empty())
        {
            pair<Node*,int>tp=q.front();
            q.pop();
            Node* node=tp.first;
            int line=tp.second;
            mp[line]=node->data;
            
            if(node->left)
            {
                q.push({node->left,line-1});
            }
            if(node->right){
                q.push({node->right,line+1});
            }
            
        }
        for(auto it:mp)res.push_back(it.second);
        
        return res;
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int>res=solve(root);
        
        return res;
        
    }
};



// } Driver Code Ends

int main()
{
    
    return 0;
}