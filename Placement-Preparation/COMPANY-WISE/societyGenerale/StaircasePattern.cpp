#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&vec)
{
   
    int n=vec.size();
    int sum=0;    

    for(auto it:vec)sum+=it;

    vector<vector<char>>mat(sum+1,vector<char>(sum+1,'-'));
    int starti=sum;
    int startj=0;

    for(int i=0;i<n;i++)
    {
        int currEle=vec[i];

       // print the height first 
        for(int j=0;j<currEle;j++)
        {
            mat[starti][startj]='*';
            starti--;
        }
        starti--;
        
    }
    
}

int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<int>vec;
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
            solve(vec);

            cout<<endl;
            cout<<endl;
        }
    }
    return 0;
}