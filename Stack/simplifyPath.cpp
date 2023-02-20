#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        
        
     path+='/';
     int n=path.length();
        stack<string>stk;

        string currentDir="";
        //stk.push(path[0]);

        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            {
                if(currentDir=="..")
                {
                    // pop if stack not empty
                    if(!stk.empty())
                    {
                        stk.pop();
                    }
                }
                else if(currentDir!="" && currentDir!=".")
                {
                    stk.push(currentDir);
                }
                currentDir="";
            }
            else{
                currentDir+=path[i];
            }
        }

    //    while(!stk.empty())
    //    {
    //        cout<<stk.top();
    //        stk.pop();
    //    }

       string fres="";

       while(!stk.empty())
       {
           string a=stk.top()+"/";
           fres.insert(0,a);
           
           stk.pop();
       }

       fres.insert(0,"/");


       cout<<fres;
       
       fres.pop_back();

       if(fres=="")return "/";
     
     return fres;
    }
};

int main()
{
    
    return 0;
}