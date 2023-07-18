#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{

    int n;
    cin>>n;

    vector<vector<char>>mat;

    for(int i=0;i<n;i++)
    {
        vector<char>vec;
        for(int j=0;j<n;j++)
        {
            char a;
            cin>>a;
            vec.push_back(a);
        }
        mat.push_back(vec);
    }

    // clockwise rotate 90
    
    // take transpose a matrix
   
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<i;j++)
     {
         swap(mat[i][j],mat[j][i]);
     }
   }


    for(int i=0;i<n;i++)
    {
        vector<char>vec=mat[i];
        reverse(vec.begin(),vec.end());
        mat[i]=vec;
    }
    

    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(mat[j][i]=='x')count++;
        }
        for(int j=0;j<count;j++)
        {
            mat[n-j-1][i]='x';
        }
        for(int j=count;j<n;j++)
        {
            mat[n-j-1][i]='o';
        }
    }
   
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<mat[i][j]<<" ";
        cout<<endl;

    }
    
    return 0;
}