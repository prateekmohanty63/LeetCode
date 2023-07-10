//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// T(N)=O(N)
// S(N)=O(N)

class Solution{
    public:
    vector<int> solve(Node* root)
    {
        if(!root)return {};
        // level order traversal
        queue<Node*>q;
        q.push(root);
        vector<int>res;
        int turn=0;
        
        while(!q.empty())
        {
           int size=q.size();
           vector<int>vec;
           for(int i=0;i<size;i++)
           {
               Node* currNode=q.front();
               q.pop();
               vec.push_back(currNode->data);
               
               if(currNode->left)q.push(currNode->left);
               if(currNode->right)q.push(currNode->right);
           }
           if(turn%2==0)
           {
                 for(int i=0;i<vec.size();i++)res.push_back(vec[i]);
           }
           else{
               for(int i=vec.size()-1;i>=0;i--)res.push_back(vec[i]);
           }
           turn++;
            
        }
        return res;
    }
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	
    	return solve(root);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{
    return 0;
}
// } Driver Code Ends