#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;


class UndergroundSystem {
public:
    map<int,pair<string,int>>checkInOrder;
    map<pair<string,string>,pair<int,int>>avgTimeTaken;

    UndergroundSystem() {
       checkInOrder.clear();
        avgTimeTaken.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<string,int>pr;
        pr.first=stationName;
        pr.second=t;
        checkInOrder[id]=pr;
    }
    
    void checkOut(int id, string stationName, int t) {
        // current station in which the user is present
        string checkInStation=checkInOrder[id].first;
        int CheckInTime=checkInOrder[id].second;

        string checkOutStation=stationName;
        int checkOutTime=t;

        avgTimeTaken[{checkInStation,checkOutStation}].first+=checkOutTime-CheckInTime;
        avgTimeTaken[{checkInStation,checkOutStation}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double timeTravel=avgTimeTaken[{startStation,endStation}].first;
        double totalCount=avgTimeTaken[{startStation,endStation}].second;
        double res=timeTravel/(double)totalCount;

        return res;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */


// TLE:O(N*Queries)

class UndergroundSystem {
public:
   
   unordered_map<int,bool>checkInStatus;
   unordered_map<int,vector<pair<string,int>>>checkInOrder;
   unordered_map<int,vector<pair<string,int>>>checkOutOrder;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        // check if the person is already checked in at any other station or not
        if(checkInStatus.find(id)==checkInStatus.end() || checkInStatus[id]==false){
               pair<string,int>pr;
               pr.first=stationName;
               pr.second=t;
               checkInOrder[id].push_back(pr);

               // mark the status of the person checkInStatus as true
               checkInStatus[id]=true;
        }
    }
    
    void checkOut(int id, string stationName, int t) {
       pair<string,int>pr;
       pr.first=stationName;
       pr.second=t;
       checkOutOrder[id].push_back(pr);

       // mark the checkInStatus as false
       checkInStatus[id]=false;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avgTime=0;
        double count=0;
        vector<int>userCheckIn;
        vector<int>userCheckOut;

        // traversing all the user checkIns and checking when the user checkIn

        for(auto it:checkInOrder)
        {
            int userId=it.first;
            vector<pair<string,int>>checkInStations=it.second;
            for(int i=0;i<checkInStations.size();i++)
            {
                string station=checkInStations[i].first;
                if(station==startStation){
                    int checkIntime=checkInStations[i].second;
                    vector<pair<string,int>>checkOutStations=checkOutOrder[it.first];
                    if(i<checkOutStations.size() && checkOutStations[i].first==endStation)
                    {
                        int checkOutTime=checkOutStations[i].second;
                        avgTime+=(checkOutTime-checkIntime);
                        count++;
                    }
                }
            }

        }

        double res=avgTime/(double)count;

        return res;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main()
{
    
    return 0;
}