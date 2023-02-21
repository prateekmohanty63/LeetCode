#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


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