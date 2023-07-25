#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<map>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)return a;

    return gcd(b,a%b);
}

pair<int,int> getReducedForm(int dy,int dx)
{
    // calculating dy/dx
   
   // get the sign of the slope 
   bool sign=(dy<0)^(dx<0);
   int g=gcd(abs(dy),abs(dx));

   if(sign)
   {
       // different sign 
       return {-abs(dy)/g,abs(dx)/g};
   }
   else{
     // they are of the same sign
     return {abs(dy)/g,abs(dx)/g};
   }

}

int solve(vector<vector<int>>&mat,int x0,int y0)
{
    int res=0;
    map<pair<int,int>,bool>slopes;
    unordered_map<double,bool>slp;

    for(int i=0;i<mat.size();i++)
    {
        int  x1=mat[i][0];
        int y1=mat[i][1];
        
        pair<int,int>p=getReducedForm(y1-y0,x1-x0);
        cout<<p.first<<" "<<p.second<<endl;
        double s=(y1-y0)/(double)(x1-x0);
        slopes[p]=true;
        slp[s]=true;

        
    }
    for(auto it:slp)cout<<it.first<<" ";

   return slp.size();
}

int main()
{
    int n;
    cin>>n;

    int x0,y0;
    cin>>x0>>y0;

    vector<vector<int>>mat;

    for(int i=0;i<n;i++)
    {
        vector<int>vec;
        int x,y;
        cin>>x>>y;
        vec.push_back(x);
        vec.push_back(y);
        mat.push_back(vec);
    }   

    int res=solve(mat,x0,y0);
    cout<<res;
    return 0;
}