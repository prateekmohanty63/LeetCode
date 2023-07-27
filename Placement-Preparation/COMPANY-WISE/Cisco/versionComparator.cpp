#include<iostream>
using namespace std;

bool isNum(char a)
{
    return (a=='1' || a=='2' || a=='3' || a=='4'|| a=='5' || a=='6' || a=='7' || a=='8' || a=='9');
}

int main()
{
    string a,b;
    cin>>a>>b;
    
    string os1,os2;

    int numPos1,numPos2;

    int n=a.length();
    int m=b.length();

    for(int i=0;i<n;i++)
    {
        if(isNum(a[i]))
        {
            numPos1=i;
            break;
        }
        else{
            os1+=a[i];
        }
    }
     for(int i=0;i<m;i++)
    {
        if(isNum(b[i]))
        {
            numPos2=i;
            break;
        }
        else{
            os2+=b[i];
        }
    }
   

    if(os1!=os2)cout<<"Invalid"<<endl;
    int flag=0; 

    cout<<os1<<" "<<os2<<endl;
    cout<<numPos1<<" "<<numPos2<<endl;

    while(numPos1<n && numPos2<m)
    {
        if(a[numPos1]<b[numPos2]){
            flag=1;
        cout<<"V1 is lower";
        break;
        }
        else if(a[numPos1]>b[numPos2])
        {
            flag=1;
            cout<<"V1 is greater";
            break;
        }
        numPos1+=2;
        numPos2+=2;
    }
   cout<<numPos1<<" "<<numPos2<<" "<<flag;
   if(flag==0){

    if(numPos1>=n && numPos2>=m)cout<<"Same";

    else if(numPos1>=n)cout<<"V1 is lower";
    
    else cout<<"V1 is greater";
   }

    return 0;
}