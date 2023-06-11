#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

class SnapshotArray {
public:
   vector<int>vec;
   map<pair<int,int>,int>mp;
   int totalSnap=0;

    SnapshotArray(int length) {

        vec.resize(length,0);
        for(int i=0;i<length;i++)mp[{totalSnap,i}]=0;
    }
    
    void set(int index, int val) {
        mp[{totalSnap,index}]=val;
        vec[index]=val;
    }
    
    int snap() {

        totalSnap++;
        return totalSnap-1;
    }
    
    int get(int index, int snap_id) {
     
      if(mp.find({snap_id,index})!=mp.end())return mp[{snap_id,index}];
      
      int res;
      int minDiff=INT_MAX;
       
       for(auto it:mp)
       {
           int snapVal=it.first.first;
           int ind=it.first.second;

           if(snapVal<=snap_id)
           {
               if((snap_id-snapVal)<=minDiff && ind==index)
               {
                   minDiff=snap_id-snapVal;
                   res=it.second;
               }
           }
       }
    
      return res;

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main()
{
    
    return 0;
}