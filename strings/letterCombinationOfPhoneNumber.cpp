#include<iostream>
#include<vector>
#include<map>

using namespace std;


// DFS SOLUTION

class Solution {
public:

    void dfs(string digits,string path,vector<string>&result,int index)
    {
        // base case

        if(index==digits.length())
        {
            result.push_back(path);
            return ;
        }

        vector<string>vec=mapping(digits[index]);

        for(auto it:vec)
        {
            dfs(digits,path+it,result,index+1);
        }
    }
    
     vector<string> mapping(char c)
    {
        switch (c)
        {
            case '0': return {};
            case '1': return {};
            case '2': return {"a","b","c"};
            case '3': return {"d","e","f"};
            case '4': return {"g","h","i"};
            case '5': return {"j","k","l"};
            case '6': return {"m","n","o"};
            case '7': return {"p","q","r","s"};
            case '8': return {"t","u","v"};
            case '9': return {"w","x","y","z"};
            default: return {};
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits=="")return {};

        string path="";

        vector<string>res;

        int index=0;

        dfs(digits,path,res,0);

        return res;


    }
};


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