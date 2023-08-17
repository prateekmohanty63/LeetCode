#include<iostream>
using namespace std;


int solve(string a)
{
    
   int n=a.length();

   int minimMoves=0;

   if(n==1)return 0;

   if(n==2)
   {
    minimMoves+=abs(a[0]-a[1]);
    return minimMoves;
   }

   // abcdefghi
   // aacdefgii
   
   int start=2;
   int end=n-3;
   int cost=abs(a[0]-a[1])+abs(a[n-1]-a[n-2]);


}

int main()
{
    string a;
    cin>>a;


    return 0;
}