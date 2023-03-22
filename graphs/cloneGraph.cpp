#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
 
   Node* clone(Node* node,unordered_map<Node*,Node*>&mp)
   {
       // base case

       // if node is already cloned return the cloned node

       if(mp.find(node)!=mp.end())return mp[node];

       Node* copyNode=new Node(node->val);

       // mapping the original node to the new node
       mp[node]=copyNode;

       for(auto it:node->neighbors)
       {
           Node *nod=clone(it,mp);
           copyNode->neighbors.push_back(nod);
       }
       return copyNode;
   }

    Node* cloneGraph(Node* node) {

        if(!node)return node;
        
        unordered_map<Node*,Node*>oldToNew;
       
       Node* res=clone(node,oldToNew);

       return res;

    }
};

int main()
{
    
    return 0;
}