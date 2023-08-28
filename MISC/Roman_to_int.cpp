
#include <iostream>
#include<map>
#include <iterator>

using namespace std;

int romanToInt(string s) {

        int a=s.length();
        int sum=0;
        map<char,int>Roman;
   Roman.insert(pair<int, int>('I',1));
   Roman.insert(pair<int, int>('V',5));
   Roman.insert(pair<int, int>('X',10));
   Roman.insert(pair<int, int>('L',50));
   Roman.insert(pair<int, int>('C',100));
   Roman.insert(pair<int, int>('D',500));
   Roman.insert(pair<int, int>('M',1000));
         map<char, int>::iterator itr;

        for(int i=0;i<a-1;i++)
        {
            if(s[i]=='I' && s[i+1]=='V'){
                sum+=4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X'){
                sum+=9;
                i++;}
            else if(s[i]=='X' && s[i+1]=='c'){
                sum+=90;
                i++;}
            else if(s[i]=='X' && s[i+1]=='L'){
                sum+=40;
                i++;}
            else if(s[i]=='C' && s[i+1]=='D'){
                sum+=400;
                i++;}
            else if(s[i]=='C' && s[i+1]=='M'){
                sum+=900;
                i++;}
            else
            {
                for(itr=Roman.begin();itr!=Roman.end();itr++)
                {
                    if(itr->first==s[i])
                        sum+=itr->second;
                }
            }
        }
        return sum;
    }

int main()
{
    cout<<romanToInt("MCMXCI");
    return 0;
}
