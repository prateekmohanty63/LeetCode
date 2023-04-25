#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;


class SmallestInfiniteSet {
public:
  
  unordered_map<int,bool>mp;

    SmallestInfiniteSet() {
        
        for(int i=1;i<=1000;i++)
        {
            mp[i]=true;
        }
    }
    
    int popSmallest() {
        
        int minim=INT_MAX;

        for(auto it:mp)
        {
            if(it.first<minim)minim=it.first;
        }
        mp.erase(minim);
        return minim;
    }
    
    void addBack(int num) {
        
        mp[num]=true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main()
{
    
    return 0;
}