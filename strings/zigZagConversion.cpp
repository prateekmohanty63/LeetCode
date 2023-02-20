#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows==1)return s;

        int n=s.length();

        if(n==1)return s;
        
        string res;

        for(int i=0;i<numRows;i++)
        {
            int incr=2*(numRows-1);
            for(int j=i;j<n;j+=incr)
            {
                res+=s[j];

                if(i>0 && i<numRows-1 && (j+incr-2*i)<n)
               {
                  res+=s[j+incr-2*i];
               }
            }

            
        }
        return res;
    }
};

// code giving wrong answer check
class Solution {
public:
    string convert(string s, int numRows) {
        
        int n=s.length();

        if(n==1)return s;

        vector<vector<char>>mat;

       // initilizing the matrix

        for(int i=0;i<n;i++)
        {
            vector<char>vec;
            for(int j=0;j<n;j++)
            {
                vec.push_back('-');
            }
            mat.push_back(vec);
        }
         
         int k=0;
         
         for(int i=0;i<n;i++)
         {
             if(i==0)
             {
                 for(int j=0;j<numRows;j++)
                 {
                     mat[j][i]=s[k];
                     k++;

                     if(k>=n)break;
                 }
             }
             else if(i%(numRows-1)==0)
             {
                for(int j=0;j<numRows;j++)
                {
                    mat[j][i]=s[k];
                    k++;

                      if(k>=n)break;
                } 
             }
             else{
                 int r=1;
                 for(int j=numRows-2;j>=1;j--)
                 {
                     mat[j][r]=s[k];
                     cout<<s[k]<<endl;
                     k++;
                     r++;

                     if (k>=n)break;
                 }
             }

             if(k>=n)break;
         }

        n=mat.size();
        int m=mat[0].size();
         
         string res;

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(mat[i][j]!='-'){
                     cout<<mat[i][j];
                     res+=mat[i][j];
                 }

                 if(mat[i][j]=='-')cout<<" ";

             }
             cout<<endl;
         }
         return res;
    }
};

int main()
{
    
    return 0;
}