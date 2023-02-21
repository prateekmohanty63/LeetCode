#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;



// most efficient method
// O(1) get and put , becuase of linked list

class LRUCache {
public:
class Node{  
   public:

    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int _key,int _val)
    {
        key=_key;
        val=_val;
    }
};

  unordered_map<int,Node*>cache;
  Node* head=new Node(-1,-1);
  Node* tail= new Node(-1,-1);
  int maxCapacity;


    LRUCache(int capacity) {
        
        maxCapacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node *node)
    {
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
       
       
    }

    void delNode(Node *delnode)
    {
       Node* delPrev=delnode->prev;
       Node* delNext=delnode->next;

       delPrev->next=delNext;
       delNext->prev=delPrev;
    }
    
    int get(int key) {
        
        if(cache.find(key)!=cache.end())
        {
            Node *node=cache[key];
            cache.erase(key);
            delNode(node);
            addNode(node);
            
            cache[key]=head->next;

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end())
        {
            Node *node=cache[key];
            cache.erase(key);

            delNode(node);
           
        }

        if(maxCapacity==cache.size())
        {
            cache.erase(tail->prev->key);
            delNode(tail->prev);
            
            
        }
        
       Node *node=new Node(key,value);
       addNode(node);
       cache[key]=head->next;

   
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// logic correct
// giving TLE
// The functions get and put must each run in O(1) average time complexity.
// this code is running in O(N)


class LRUCache {
public:   

    int maxCapacity;
    unordered_map<int,int>cache;
    vector<int>usedOrder;


    LRUCache(int capacity) {
         
         maxCapacity=capacity;
    }
    
    int get(int key) {

        if(cache.find(key)!=cache.end()){
        
          for(int i=0;i<usedOrder.size();i++)
          {
              if(usedOrder[i]==key)
              {
                  usedOrder.erase(usedOrder.begin()+i);
                  break;
              }
          }

          usedOrder.push_back(key);
          return cache[key];
        }

        return -1;
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end())
        {
            for(int i=0;i<usedOrder.size();i++)
            {
                if(usedOrder[i]==key)
                {
                    usedOrder.erase(usedOrder.begin()+i);
                    break;
                }
            }
            usedOrder.push_back(key);

            cache[key]=value;
            return ;
        }

        maxCapacity--;

        if(maxCapacity<0)
        {
               
             int keyToRemove=usedOrder[0];

            cache.erase(keyToRemove);
            usedOrder.erase(usedOrder.begin());
        }
        cache[key]=value;
        usedOrder.push_back(key);
    }
};


// check the code
class LRUCache {
public:   

    int maxCapacity;
    unordered_map<int,int>cache;
    vector<int>usedOrder;
    unordered_map<int,int>keyVal;


    LRUCache(int capacity) {
         
         maxCapacity=capacity;
    }
    
    int get(int key) {

        if(cache.find(key)!=cache.end()){
        
         int i=keyVal[key];
         usedOrder.erase(usedOrder.begin()+i);
         usedOrder.push_back(key);
         keyVal[key]=usedOrder.size()-1;

          return cache[key];
        }

        return -1;
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end())
        {
           int i=keyVal[key];
           usedOrder.erase(usedOrder.begin()+i);   
           usedOrder.push_back(key);
           keyVal[key]=usedOrder.size()-1;

            cache[key]=value;
            return ;
        }

        maxCapacity--;

        if(maxCapacity<0)
        {
               
            int keyToRemove=usedOrder[0];

            cache.erase(keyToRemove);
            usedOrder.erase(usedOrder.begin());
            keyVal.erase(keyToRemove);
        }
        cache[key]=value;
        usedOrder.push_back(key);
        keyVal[key]=usedOrder.size()-1;

    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    
    return 0;
}