#include<iostream>
#include<queue>
using namespace std;



class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>>q;
        string res="";
        
        if(a)
         q.push({a,'a'});

         if(b)
         q.push({b,'b'});

         if(c)
         q.push({c,'c'});

         while(q.size()>1)
         {
             pair<int,char>one=q.top();q.pop();
             pair<int,char>two=q.top();q.pop();

             if(one.first>=2)
             {
                res+=one.second;
                res+=one.second;

                one.first-=2;
             }
             else
             {
                 res+=one.second;
                 one.first--;
             }

             if(two.first>=2 && two.first>=one.first)
             {
                 res+=two.second;
                 res+=two.second;

                 two.first-=2;
             }
             else
             {
                 res+=two.second;
                  
                  two.first--;
             }

             if(one.first>0)
             {
                 q.push(one);
             }
             if(two.first>0)
             {
                 q.push(two);
             }
         }

         if(q.empty())return res;

        
             pair<int,char>p=q.top();
             

             if(p.first>=2)
             {
                 res+=p.second;
                 res+=p.second;
             }
             else
             {
                 res+=p.second;
             }
         

         return res;
    }
};

int main()
{
    
    return 0;
}