#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    vector<string>res;
    void buildIp(string s,int i,int dots,string curr)
    {
        // base case

        if(dots==4 && i>=s.length())
        {
            // remove the last dot from the current-IP
            curr.pop_back();
            res.push_back(curr);
            return ;
        }

        if(dots>4)return ;
        
        string temp;

       for(int j=i;j<s.length();j++)
       {
           temp+=s[j];
            
            // string contains a leading 0
            if(temp.length()>1 && temp[0]=='0')return ;

            int r=stoi(temp);

            if(r>=0 && r<=255)
            {
                buildIp(s,j+1,dots+1,curr+temp+'.');
            }
            else{
                return ;
            }
  
  
       }
    }


    vector<string> restoreIpAddresses(string s) {
        
       // vector<string>res;
        
        int n=s.length();

        if(n>12)return res;

        string curr;

        // generating IP addresses


       buildIp(s,0,0,curr);

       
        return res;
    }
};

int main()
{
    
    return 0;
}