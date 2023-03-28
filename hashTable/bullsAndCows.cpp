#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        
        string res;

        int n=secret.size();

        int numberOfBull=0;
        int numberOfCows=0;

        unordered_map<char,vector<int>>secPresent;
        unordered_map<char,int>outOfOrder;

        for(int i=0;i<n;i++)
        {
            secPresent[secret[i]].push_back(i);
            if(secret[i]==guess[i])numberOfBull++;
        } 

        for(int i=0;i<n;i++)
        {
            if(secPresent.find(guess[i])!=secPresent.end())
            {  
                if(guess[i]!=secret[i])
                outOfOrder[guess[i]]++;
            }
        }

        for(auto it:outOfOrder)
        {
            if(secPresent.find(it.first)!=secPresent.end())
            {
               
                vector<int>vec=secPresent[it.first];

                for(int i=0;i<vec.size();i++)
                {
                    if(outOfOrder[it.first]>0 && guess[vec[i]]!=secret[vec[i]])
                    {
                         numberOfCows++;
                         outOfOrder[it.first]--;
                    }
                }
            }
        }
        
       
        res+=to_string(numberOfBull)+"A"+to_string(numberOfCows)+"B";

        return res;

    }
};

int main()
{
    
    return 0;
}