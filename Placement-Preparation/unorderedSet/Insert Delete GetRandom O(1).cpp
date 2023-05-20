#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class RandomizedSet {
public:
unordered_set<int>set1;
vector<int>vec;
unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if(set1.find(val)==set1.end()){
        set1.insert(val);
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
        }
        return false;
    }
    
    bool remove(int val) {
        
        if(set1.find(val)!=set1.end())
        {
           set1.erase(val);
           int indPresent=mp[val];
           mp.erase(val);
           vec[indPresent]=vec[vec.size()-1];
           mp[vec[vec.size()-1]]=indPresent;
           vec.pop_back();

            return true;
        }
        return false;
    }
    
    int getRandom() {
        // generate a random index from 0 to vec.size()-1;

        int randomIndex=rand()%vec.size();

        return vec[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    
    return 0;
}