#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        unordered_map<int,vector<string>>row,col;
        unordered_map<string,bool>taken;

        int res=0;

        // adding the servers row-wise

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    string coord=to_string(i)+"*"+to_string(j);
                    row[i].push_back(coord);
                }
            }
        }

        // adding the servers col-wise

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                {
                    string coord=to_string(j)+"*"+to_string(i);
                    col[i].push_back(coord);
                }
            }
        }

        for(auto it:row)
        {
            int key=it.first;
            vector<string>val=it.second;
            cout<<key<<" ";

            for(int i=0;i<val.size();i++)
            {
                cout<<val[i]<<" ";
            }
            cout<<endl;
        }

   cout<<endl<<endl;
        for(auto it:col)
        {
            int key=it.first;
            vector<string>val=it.second;
            cout<<key<<" ";

            for(int i=0;i<val.size();i++)
            {
                cout<<val[i]<<" ";
            }
            cout<<endl;
        }

     for(auto it:row)
     {
         if(it.second.size()>=2)
         {
             res+=it.second.size();
             vector<string>coord=it.second;

             for(int i=0;i<coord.size();i++)
             {
                 taken[coord[i]]=true;
             }
         }
     }

     for(auto it:col)
     {
         if(it.second.size()>=2)
         {
             vector<string>coord=it.second;

             for(int i=0;i<coord.size();i++)
             {
                 if(taken.find(coord[i])==taken.end())
                 {
                     res++;
                     taken[coord[i]]=true;
                 }
             }
         }
     }
        
        return res;
    }
};

int main()
{
    
    return 0;
}