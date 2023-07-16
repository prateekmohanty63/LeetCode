#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int main()
{
    map<pair<string,string>,bool>mp;

    int n=4;
    int m=4;

    vector<vector<string>>customer={{"english","carpenter"},{"hindi","carpenter"},{"spanish","plumber"},{"english","lawyer"}};
    vector<vector<string>>artist={{"english","plumber"},{"spanish","plumber"},{"hindi","carpenter"},{"english","doctor"}};

    for(int i=0;i<m;i++)
    {
        mp[{artist[i][0],artist[i][1]}]=true;
    }

    int count=0;

    for(auto it:customer)
    {
        pair<string,string>pr;
        pr.first=it[0];
        pr.second=it[1];
        if(mp.find(pr)!=mp.end())
        {
            if(mp[pr]==true){
                count++;
                mp[pr]=false;
            }
        }
    }

    cout<<n-count;


    return 0;
}