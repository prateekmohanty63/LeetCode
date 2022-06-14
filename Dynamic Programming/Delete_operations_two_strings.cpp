#include<iostream>
#include<map>
#include<vector>
using namespace std;

// solution doesn't pass all test cases (926/1306)

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.length();
        int m=word2.length();
        int count=0;
        map<char,int>map1,map2;
        
        
        for(int i=0;i<n;i++)
        {
            map1[word1[i]]++;
        }
        
         for(int i=0;i<m;i++)
        {
            map2[word2[i]]++;
        }
        
        for(int i=0;i<m;i++)
        {
            auto it = map1.find(word2[i]);
            if(it==map1.end()){
                it->second=0;
                count++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            auto it=map2.find(word1[i]);
            if(it==map2.end()){
                it->second=0;
                count++;
            }
        }
       // if present
        map<char,int>::iterator itr;
        
        for(itr=map1.begin();itr!=map1.end();itr++)
        {
            char a=itr->first;
            auto it=map2.find(a);
            if(it!=map2.end())
            {
                count+=abs(itr->second-it->second);
                
                if(itr->second>it->second)
                {
                    it->second=0;
                    itr->second-=it->second;
                }
                else{
                    itr->second=0;
                    it->second-=itr->second;
                }
            }
        }
        
        // remaining characters
        string a,b;
        for(itr=map1.begin();itr!=map1.end();itr++)
        {
            if(itr->second!=0){
                a+=itr->first;
            }
        }
        
          for(itr=map2.begin();itr!=map2.end();itr++)
        {
            if(itr->second!=0){
                b+=itr->first;
            }
        }
        cout<<a<<" "<<b;
       return count;
        
    }
};

int main()
{
    
    return 0;
}