#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n=garbage.size();
        int m=travel.size();
        int totalGarbagePresent=0;
        int totalTimeTaken=0;

        unordered_map<char,int>mp;
        
        vector<int>preFixSum(m,0);
        preFixSum[0]=travel[0];

       for(int i=1;i<m;i++)
       {
           preFixSum[i]=preFixSum[i-1]+travel[i];
       }

        mp['g']=0;
        mp['p']=0;
        mp['m']=0;

        for(int i=0;i<n;i++)
        {
            totalGarbagePresent+=garbage[i].size();
        }

        // max index till glass
        for(int i=0;i<n;i++)
        {
            string a=garbage[i];
            int glassPresent=0;
            int paperPresent=0;
            int metalPresent=0;

        

            for(int j=0;j<a.length();j++)
            {
                if(a[j]=='G')glassPresent=1;

                else if(a[j]=='P')paperPresent=1;

                else metalPresent=1;
            }
            if(glassPresent==1)mp['g']=max(mp['g'],i);

            if(paperPresent==1)mp['p']=max(mp['p'],i);

            if(metalPresent==1)mp['m']=max(mp['m'],i);
        }

        totalTimeTaken=totalGarbagePresent;

        cout<<mp['g']<<" "<<mp['p']<<" "<<mp['m'];

        if(mp['g']!=0)totalTimeTaken+=preFixSum[mp['g']-1];

        if(mp['p']!=0)totalTimeTaken+=preFixSum[mp['p']-1];

        if(mp['m']!=0)totalTimeTaken+=preFixSum[mp['m']-1];

        return totalTimeTaken;
    }
};

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n=garbage.size();
        int m=travel.size();
        vector<int>glassPresent(n,0);
        vector<int>paperPresent(n,0);
        vector<int>metalPresent(n,0);

        int totalTimeTaken=0;

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++)
        {
            string a=garbage[i];
            int countOfGlass=0;
            int countOfPaper=0;
            int countOfMetal=0;

            for(int j=0;j<a.length();j++)
            {
                if(a[j]=='G')countOfGlass++;

                else if(a[j]=='P')countOfPaper++;

                else countOfMetal++;
            }
            vector<int>vec;
            vec.push_back(countOfGlass);
            vec.push_back(countOfPaper);
            vec.push_back(countOfMetal);
        }

        glassPresent[n-1]=0;
        paperPresent[n-1]=0;
        metalPresent[n-1]=0;

        for(int i=n-2;i>=0;i--)
        {
            string a=garbage[i+1];
            int countOfGlass=0;
            int countOfPaper=0;
            int countOfMetal=0;

            for(int j=0;j<a.length();j++)
            {
                if(a[j]=='G')countOfGlass++;

                else if(a[j]=='P')countOfPaper++;

                else countOfMetal++;
            }
            glassPresent[i]=glassPresent[i+1]+countOfGlass;
            paperPresent[i]=paperPresent[i+1]+countOfPaper;
            metalPresent[i]=metalPresent[i+1]+countOfMetal;
        }

        // taking glass truck

        for(int i=0;i<n;i++)
        {
            totalTimeTaken+=mp[i][0];

             if(glassPresent[i]==0)break;

            
            if(i<m)totalTimeTaken+=travel[i];

        }

        // taking paper truck
        for(int i=0;i<n;i++)
        {

            totalTimeTaken+=mp[i][1];

             if(paperPresent[i]==0)break;

             if(i<m)totalTimeTaken+=travel[i];
        }
        
        // taking metal truck
        for(int i=0;i<n;i++)
        {
            totalTimeTaken+=mp[i][2];

            if(metalPresent[i]==0)break;

            if(i<m)totalTimeTaken+=travel[i];
        }
        return totalTimeTaken;
    }
};

int main()
{
    
    return 0;
}