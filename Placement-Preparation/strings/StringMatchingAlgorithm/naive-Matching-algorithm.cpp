#include<iostream>
using namespace std;

// T(N)=O(n*m)

int main()
{
    string a="1011000110",b="111";
  //  cin>>a>>b;

    int n=a.length();
    int m=b.length();
    int flag1=0;

    for(int i=0;i<=n-m;i++)
    {
        if(a[i]==b[0]){
            int k=0;
            int flag=0;

            while(k<m)
            {
                if(a[i+k]!=b[k]){
                    flag=1;
                    break;
                }
                k++;
            }
            if(flag==0){
                flag1=1;
                cout<<"Matching found at index: "<<" "<<i<<endl;
            }
        }
    }
    if(flag1==0)cout<<"No match found";
    return 0;
}