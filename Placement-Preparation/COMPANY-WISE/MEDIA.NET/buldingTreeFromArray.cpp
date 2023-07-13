#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node* newNode(int data)
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

Node* buildTree(vector<int>&vec,int i)
{
    Node* root=nullptr;
    int n=vec.size();

    // base case for recursion 
    if(i<n)
    {
        root=newNode(vec[i]);

        // insert left child
        root->left=buildTree(vec,2*i+1);

        // insert right child
        root->right=buildTree(vec,2*i+2);
    }
    return root;
}

void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}

void bfs(Node* root)
{
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left)q.push(curr->left);

        if(curr->right)q.push(curr->right);
    }

    return ;
}

bool hasPath(Node* root,vector<int>&arr,int target)
{
    // base case 
    if(!root)return false;

    // push the node's value in arr 
    arr.push_back(root->data);

    if(root->data==target)return true;

    if(hasPath(root->left,arr,target) || hasPath(root->right,arr,target))
    return true;

    arr.pop_back();
    return false;
}

int main()
{
    vector<int>vec={ 1, 5, 3, 4, 2, 6,7 };
    Node* root=buildTree(vec,0);
  //  inOrder(root);
    //cout<<endl;
   // bfs(root);

    int x=2;
    int y=2;
   
    vector<int>vec1;
    cout<<hasPath(root,vec1,y);
    cout<<endl;
    for(auto it:vec1)cout<<it<<" ";
    cout<<endl;
    double maxVal=pow(x,y);
    for(int i=vec1.size()-1;i>=0;i--)maxVal=max(maxVal,pow(x,vec1[i]));
    cout<<maxVal;
    return 0;
}