#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;


class TimeMap {
public:
    
    int binSearch(vector<int>&vec,int target)
    {
        int start=0;
        int end=vec.size()-1;
        int closestEle=INT_MAX;
        int closestInd=-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(vec[mid]==target)return mid;

           if(target>vec[mid])
           {
              if(target-vec[mid]<=closestEle)
              {
                    closestEle=target-vec[mid];
                    closestInd=mid;
              }
              start=mid+1;
           }
           else{
              
               end=mid-1;
           }
        }
        return closestInd;
    }

    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int>pr;
        pr.first=value;
        pr.second=timestamp;
        mp[key].push_back(pr);
    }
    
    string get(string key, int timestamp) {
      int start = 0;
        int end = mp[key].size()-1;

        while(start <= end)
        {
            int mid = (start + end)/2;
            int time = mp[key][mid].second;

            if(time == timestamp)
            {
                return mp[key][mid].first;
            }  
            else if(timestamp < time)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        if(end >=0 and end<mp[key].size())
        {
            return mp[key][end].first;
        }
        return "";

    }
};


class TimeMap {
public:
    
    int binSearch(vector<int>&vec,int target)
    {
        int start=0;
        int end=vec.size()-1;
        int closestEle=INT_MAX;
        int closestInd=-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(vec[mid]==target)return mid;

           if(target>vec[mid])
           {
              if(target-vec[mid]<=closestEle)
              {
                    closestEle=target-vec[mid];
                    closestInd=mid;
              }
              start=mid+1;
           }
           else{
              
               end=mid-1;
           }
        }
        return closestInd;
    }

    unordered_map<string,vector<pair<string,int>>>keyValue;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int>pr;
        pr.first=value;
        pr.second=timestamp;
        keyValue[key].push_back(pr);
    }
    
    string get(string key, int timestamp) {
        
        vector<pair<string,int>>vec=keyValue[key];
        vector<int>vec1;
        for(auto it:vec)
        {
            vec1.push_back(it.second);
        }
        int ind=binSearch(vec1,timestamp);

        if(ind==-1)return "";

        return vec[ind].first;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    
    return 0;
}