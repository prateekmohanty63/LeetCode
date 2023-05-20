#include<iostream>
#include<unordered_map>
using namespace std;

class FrequencyTracker {
public:
    
   
    
    unordered_map<int,int>mp;
    unordered_map<int,int>mp1;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number)==mp.end()){
        mp[number]++;
        mp1[mp[number]]++;
        }
        else{
            mp1[mp[number]]--;
            mp[number]++;
            mp1[mp[number]]++;
        }
    }
    
    void deleteOne(int number) {
        
        if(mp.find(number)!=mp.end())
        {
            if(mp[number]>0){
                mp1[mp[number]]--;
                mp[number]--;
                mp1[mp[number]]++;
               
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        
        if(mp1[frequency]>0)return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

int main()
{
    
    return 0;
}