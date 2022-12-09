#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<map>
using namespace std;


// Find rectangle considering points in the for loop are diagonal points
class Solution {
public:
    
    int reactArea(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
    {
        int side1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        int side2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

        return side1*side2;
    }
   

    int minAreaRect(vector<vector<int>>& points) {

         int n=points.size();
        
       // sort(points.begin(),points.end());
       unordered_map<int,vector<int>>mp;

       for(int i=0;i<n;i++)
       {
           mp[points[i][0]].push_back(points[i][1]);
       }

       int maxArea=INT_MAX;

       
     // use diangonals to find the rectangle

     for(int i=0;i<n;i++)
     {
         int x1=points[i][0];
         int y1=points[i][1];

         for(int j=i+1;j<n;j++)
         {
            int x2=points[j][0];
            int y2=points[j][1];

            if(x1==x2 || y1==y2)continue;

            if(find(mp[x1].begin(),mp[x1].end(),y2)!=mp[x1].end() && find(mp[x2].begin(),mp[x2].end(),y1)!=mp[x2].end())
            {
                maxArea=min(maxArea,abs(x2-x1)*abs(y2-y1));
            }


         }
     }
       
        if(maxArea==INT_MAX)return 0;

        return maxArea;
    }
};


// TLE
//114/137 passing

class Solution {
public:
    
    int reactArea(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
    {
        int side1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        int side2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

        return side1*side2;
    }
   

    int minAreaRect(vector<vector<int>>& points) {

         int n=points.size();
        
        sort(points.begin(),points.end());
       map<pair<int,int>,bool>mp;

       for(int i=0;i<n;i++)
       {
           mp[make_pair(points[i][0],points[i][1])]=true;
       }

       int maxArea=INT_MAX;

       

        for(int i=0;i<n;i++)
        {
              int x1=points[i][0];
              int y1=points[i][1];

              for(int j=i+1;j<n;j++)
              {
                  int x2=points[j][0];
                  int y2=points[j][1];

                  if(x2>x1)break;

                

                  for(int k=j+1;k<n;k++)
                  {
                      int x3=points[k][0];
                      int y3=points[k][1];

                  if(y1!=y3)continue;

                      if(x1==x2 && y1==y3 && mp.find(make_pair(x3,y2))!=mp.end())
                      {
                           int area=reactArea(x1,x2,x3,x3,y1,y2,y3,y2);

                           maxArea=min(maxArea,area);
                      }
                  }
              }

 
        }

        if(maxArea==INT_MAX)return 0;

        return maxArea;
    }
};

int main()
{
    
    return 0;
}