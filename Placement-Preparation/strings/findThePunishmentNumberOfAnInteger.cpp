#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    
 
    void findSubStrings(string a,string b,vector<string>&substring,set<vector<string>>&set1)
    {
        if(a.length()==0)
        {
            vector<string>output(substring);
            set1.insert(output);
            return ;
        }
        //if(a.length()>b.length())return ;
     
        
        // recursively build the substrings 
        
        if(b.length()<=a.length()){
        for(int i=0;i<b.length();i++)
        {
            substring.push_back(a.substr(0,i+1));
            findSubStrings(a.substr(i+1),b,substring,set1);
            substring.pop_back();
        }
        }
        else{
            for(int i=0;i<a.length();i++)
        {
            substring.push_back(a.substr(0,i+1));
            findSubStrings(a.substr(i+1),b,substring,set1);
            substring.pop_back();
        }
       }
    }
    
    int punishmentNumber(int n) {
        
        int res=0;
        
        for(int i=1;i<=n;i++)
        {
            int k=i*i;
            string a=to_string(i);
            string b=to_string(k);
            
           if(a.length()==1)
           {
               if(i==1 || i==9)res+=(i*i);
           }
           else{
               // generating all possible combinations of non-overlapping substrings 
               vector<string>substr;
               set<vector<string>>set1;
               findSubStrings(b,a,substr,set1);
               
               for(auto it:set1)
               {
                   vector<string>vec=it;
                   int sum=0;
                   for(int j=0;j<vec.size();j++)
                   {
                     
                       sum+=stoi(vec[j]);
                   }
                   
                   if(sum==i)
                   {
                    //  cout<<i<<" "<<sum<<endl;
                       res+=(i*i);
                       break;
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