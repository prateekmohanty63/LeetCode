#include<iostream>
#include<queue>
#include<stack>
using namespace std;


struct Node {
  
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x)
  {
    data=x;
    left=right=NULL;
  }

};



void bfs(Node *root,vector<int>&res)
{
    if(!root)return ;
    
    queue<Node*>q;
    stack<int>stk;
    
    q.push(root);
    
    while(!q.empty())
    {
         Node *r=q.front();
         stk.push(r->data);
         q.pop();
         
         if(r->right!=NULL){
         q.push(r->right);
        
         }
         
         if(r->left!=NULL){
         q.push(r->left);
        
         }
         
        
    }
    
    while(!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
}

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    
    vector<int>res;
    
    bfs(root,res);
    //for(auto it:res)cout<<it<<" ";
   // reverse(res.begin(),res.end());
    
    return res;
}


void levelOrderTraversal(Node *node)
{
    queue<Node *>q;

    q.push(node);

    while(!q.empty())
    {
        Node *front=q.front();

        cout<<front->data<<" ";
         
         if(front->left)
        q.push(front->left);

        if(front->right)
        q.push(front->right);
    }
}

int main()
{
    
    return 0;
}