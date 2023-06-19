#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        
   int a=s.length();
   int sum=0;
   int prev=0;
   map<char,int>Roman;
   Roman.insert(pair<int, int>('I',1));
   Roman.insert(pair<int, int>('V',5));
   Roman.insert(pair<int, int>('X',10));
   Roman.insert(pair<int, int>('L',50));
   Roman.insert(pair<int, int>('C',100));
   Roman.insert(pair<int, int>('D',500));
   Roman.insert(pair<int, int>('M',1000));
         map<char, int>::iterator itr;
        
    
        for(int i=0;i<a;i++)
        {
            for(itr=Roman.begin();itr!=Roman.end();itr++)
            {
                if(s[i]==itr->first)
                    sum+=itr->second;
            }
        }
        
        for(int i=0;i<a-1;i++)
        {
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
                prev++;
               
            else if(s[i]=='X' && (s[i+1]=='C' || s[i+1]=='L'))
                prev+=10;
            
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
                prev+=100;
        }
        return sum-2*prev;
    }
};

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int>mp;

        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int res=0;

        int n=s.length();

        for(int i=n;i>=0;i--)
        {
            char ele=s[i];

            if(ele=='I')res++;

            else if(ele=='V'){
                if(i!=0){
                    if(s[i-1]!='I')res+=5;

                    else {
                        res+=4;
                        i--;
                    }
                }
                else res+=5;
            }

          else if(ele=='X'){
              if(i!=0){
                  if(s[i-1]!='I')res+=10;

                  else{
                      res+=9;
                      i--;
                  }
              }
              else res+=10;
          }

          else if(ele=='L'){
              if(i!=0){
                  if(s[i-1]!='X')res+=50;

                  else{
                      res+=40;
                      i--;
                  }
              }
              else res+=50;
          }

          else if(ele=='C'){
              if(i!=0){
                  if(s[i-1]!='X')res+=100;

                  else{
                      res+=90;
                      i--;
                  }
              }
              else res+=100;
          }
          else if(ele=='D'){
              if(i!=0){
                  if(s[i-1]!='C')res+=500;

                  else{
                      res+=400;
                      i--;
                  }
              }
              else res+=500;
          }
          else if(ele=='M'){
              if(i!=0){
                  if(s[i-1]!='C')res+=1000;

                  else{
                      res+=900;
                      i--;
                  }
              }
              else res+=1000;
          }


        }
        return res;
    }
};


int main()
{
    
    return 0;
}