#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        set<string>transformations;
        
        vector<string>table={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<char,string>mapping;
        
        for(int i=0;i<26;i++)
        {
            mapping[i]=table[i];
        }
        
        for(int i=0;i<words.size();i++)
        {
            string a=words[i];
            string res;
            
            for(int j=0;j<a.length();j++)
            {
                int index=(int)a[j]-97;
                res+=mapping[index];
            }
            transformations.insert(res);
        }
        return transformations.size();
    }
};

int main()
{
    
    return 0;
}