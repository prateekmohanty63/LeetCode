#include<iostream>
#include<vector>
#include<algorithm>
#include<priority_queue>

using namespace std;

class Solution {
public:
typedef pair<int, int> pi;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
       vector<vector<int>>vec;

       int n=trips.size();

      priority_queue<pi, vector<pi>, greater<pi> > pq;
       for(int i=0;i<n;i++)
       {
           vector<int>vec1;
           vec1.push_back(trips[i][1]);
           vec1.push_back(trips[i][2]);
           vec1.push_back(trips[i][0]);
           vec.push_back(vec1);
       }

       // sorting the vec based on to-from and passangers

       sort(vec.begin(),vec.end());

       if(capacity<vec[0][2])return false;

       int m=vec.size();

       int startPoint=vec[0][0];
       int endPoint=vec[m-1][1];
       int capRem=capacity;
       int k=0;

       for(int i=startPoint;i<=endPoint;i++)
       {
            while(!pq.empty() && pq.top().first==i)
        { 
             cout<<"IN";
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            capRem+=pq.top().second;
            pq.pop();
        }
          
           while(k<m && vec[k][0]==i)
           {
        
           if(vec[k][2]>capRem)return false;

            capRem-=vec[k][2];
            pq.push(make_pair(vec[k][1],vec[k][2]));
            k++;

        }
           cout<<i<<" "<<pq.top().first<<" "<<pq.top().second<<endl;
           
       }

        return true;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
       vector<vector<int>>vec;

       int n=trips.size();


       for(int i=0;i<n;i++)
       {
           vector<int>vec1;
           vec1.push_back(trips[i][1]);
           vec1.push_back(trips[i][2]);
           vec1.push_back(trips[i][0]);
           vec.push_back(vec1);
       }

       // sorting the vec based on to-from and passangers

       sort(vec.begin(),vec.end());

       if(capacity<vec[0][2])return false;

       int m=vec.size();

       int startPoint=vec[0][0];
       int endPoint=vec[m-1][1];
       int capRem=capacity;
       int indexComp=0;

       for(int i=startPoint;i<=endPoint;i++)
       {
           for(int j=indexComp;j<m;j++)
           {
               if(i==vec[j][0])
               {
                   int cap=vec[j][2];
                   if(capRem<cap)return false;

                   capRem-=cap;
                   
               }
               if(i==vec[j][1])
               {
                   capRem+=vec[j][2];
               }
               
           }
           
       }

        return true;
    }
};