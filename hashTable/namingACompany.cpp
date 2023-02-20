#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
   
 long distinctNames(vector<string> ideas) {
     
        unordered_set<string> groups[26];
        for (auto idea : ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }

        long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                
                long mutuals = 0;
                for (auto ideaA : groups[i]) {
                    if (groups[j].count(ideaA)) {
                        mutuals++;
                    }
                }
                answer += 2 * (groups[i].size() - mutuals) * (groups[j].size() - mutuals);
            }
        }
        
        return answer;
 }
};


class Solution {
public:
   
   bool isValid(string ideaA,string ideaB,unordered_map<string,bool>&mp)
   {
       // swap the first characters of the strings

       swap(ideaA[0],ideaB[0]);
       
       if(mp.find(ideaA)==mp.end() && mp.find(ideaB)==mp.end())return true;

       return false;

   }

    long long distinctNames(vector<string>& ideas) {
        
        unordered_map<string,bool>names;
        int n=ideas.size();

        for(auto it:ideas)
        {
            names[it]=true;
        }
        
        long long res=0;

       for(int i=0;i<n;i++)
       {
           string ideaA=ideas[i];

           for(int j=i+1;j<n;j++)
           {
               string ideaB=ideas[j];

               if(ideaA==ideaB)continue;

               if(isValid(ideaA,ideaB,names))res+=2;
           }
       }
       return res;
    }
};

int main()
{
    
    return 0;
}