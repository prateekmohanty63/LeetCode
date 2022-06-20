#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// this solution is using hast set
class Solution {
public:
    
    static bool cmp(string &a,string &b)
    {
        return a.length()>b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();
        int res=0;
        
        sort(words.begin(),words.end(),cmp);
        
//         for(int i=0;i<n;i++)
//             cout<<words[i]<<" ";
        
        unordered_set<string>set1;
        
        for(int i=0;i<n;i++)
        {
            set1.insert(words[i]);
        }
        
        for(string s:words)
        {
            for(int i=1;i<s.length();i++)
            {
                string key=s.substr(i);
                cout<<key<<" ";
                set1.erase(key);
            }
            cout<<endl;
        }
        
        unordered_set<string> :: iterator itr;
        for(itr=set1.begin();itr!=set1.end();itr++)
        {
            string a=*itr;
            //cout<<a<<" ";
            res+=a.length()+1;
            
            
        }
        return res;
    }
};


class Solution {
public:
   void sort(vector<string>&vec1,int n)
   {
       for(int i=1;i<n;i++)
       {
           string temp=vec1[i];
           
           int j=i-1;
           while(j>=0 && temp.length()>vec1[j].length())
           {
               vec1[j+1]=vec1[j];
               j--;
           }
           vec1[j+1]=temp;
       }
   }
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();
        
        // edge case
        if(n==1)
        {
            return words[0].length()+1;
        }
        
        // we definetly have to take the longest length words as they wont be substring of any word
        
        sort(words,n);
        
        
        // for(int i=0;i<n;i++)
        //     cout<<words[i]<<" ";
        
        // inlcuding all the longest words
        
       string res;
        
        
        for(int i=0;i<n;i++)
        {
            string a=words[i]+"#";
            size_t found = res.find(a);
            cout<<found<<" ";
            if(found>=res.length())res+=a;
        }
       
       //cout<<res;
        return res.length();
    }
};

int main()
{
    
    return 0;
}