#include<iostream>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0)return {};
        
        map<char,string>mp;
        mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        int n=digits.length();

        vector<string>res;


       
        if(n==1)
        {
            string a=mp[digits[0]];

            for(int i=0;i<a.length();i++)
            {
                string c;
                c+=a[i];
                res.push_back(c);
                
            }
            return res;
        }
        else if(n==2)
        {
            string a=mp[digits[0]];
            string b=mp[digits[1]];
            cout<<a<<" "<<b;

            for(int i=0;i<a.length();i++)
            {
               
                for(int j=0;j<b.length();j++)
                {
                    string r;
                    r+=a[i];
                    r+=b[j];
                    res.push_back(r);
                }
            }
        }
        else if(n==3)
        {
            string a=mp[digits[0]];
            string b=mp[digits[1]];
            string c=mp[digits[2]];

            for(int i=0;i<a.length();i++)
            {
                for(int j=0;j<b.length();j++)
                {
                    for(int k=0;k<c.length();k++)
                    {
                        string r;
                        r+=a[i];
                        r+=b[j];
                        r+=c[k];
                        res.push_back(r);
                    }
                }
            }
        }
        else{
           
            string a=mp[digits[0]];
            string b=mp[digits[1]];
            string c=mp[digits[2]];
            string d=mp[digits[3]];

            for(int i=0;i<a.length();i++)
            {
                for(int j=0;j<b.length();j++)
                {
                    for(int k=0;k<c.length();k++)
                    {
                        for(int l=0;l<d.length();l++){
                        string r;
                        r+=a[i];
                        r+=b[j];
                        r+=c[k];
                        r+=d[l];
                        res.push_back(r);
                        }
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