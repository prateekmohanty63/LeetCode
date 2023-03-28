#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        unordered_map<char,int>mp1,mp2;

        int n=word1.length();
        int m=word2.length();


        for(int i=0;i<n;i++)
        {
            mp1[word1[i]]++;
        }

        for(int i=0;i<m;i++)
        {
            mp2[word2[i]]++;
        }

       // if(mp1.size()==mp2.size())return true;

        for(auto it:mp1)
        {
            for(auto itr:mp2)
            {
                unordered_map<char,int>temp1=mp1,temp2=mp2;

                // adding new char to map2

                temp2[it.first]++;

                // adding new char to map1

                temp1[itr.first]++;

                // removing the swapped element from both the maps

                temp2[itr.first]--;
                temp1[it.first]--;

                if(temp2[itr.first]==0)
                temp2.erase(itr.first);


                if(temp1[it.first]==0)
                temp1.erase(it.first);

                if(temp1.size()==temp2.size())return true;
            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}