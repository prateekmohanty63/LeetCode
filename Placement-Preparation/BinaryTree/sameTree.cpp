#include<iostream>
using namespace std;

// T(N)=O(N)
// S(N)=O(H)


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

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        // base case
        if(!r1 && !r2)return true;
        
        if(!r1)return false;
        if(!r2)return false;

        if(r1->data!=r2->data)return false;

  return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
};

int main()
{
    
    return 0;
}