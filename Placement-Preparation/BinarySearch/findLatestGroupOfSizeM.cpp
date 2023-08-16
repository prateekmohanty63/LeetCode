#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool hasGroup(string a,int m)
    {
        int n=a.size();
        int start=0;
        int end=m-1;

        int count1s=0;

        for(int i=start;i<=end;i++)
        {
            if(a[i]=='1')count1s++;
        }

        while(end<n)
        {
            if(count1s==m)
            {
                if(start-1>=0 && end+1<n)
                {
                    if(a[start-1]=='0' && a[end+1]=='0')return true;
                }
                else if(start-1<0 && end+1<n)
                {
                    if(a[end+1]=='0')return true;
                }
                else if(end+1<=n && start-1>=0)
                {
                    if(a[start-1]=='0')return true;
                }
                else return true;
            }
            if(a[start]=='1')count1s--;
            start++;
            end++;
            if(end<n && a[end]=='1')count1s++;
        }
        return false;

    }
    int findLatestStep(vector<int>& arr, int m) {
        
        int n=arr.size();
        int start=1;
        int end=n;
        int ind=-1;

       
        string bits;
        for(int i=0;i<n;i++)bits+='0';

        for(int i=0;i<n;i++)
        {
            bits[arr[i]-1]='1';
        }

        for(int i=n-1;i>=0;i--)
        {
            if(hasGroup(bits,m))return i+1;

            bits[arr[i]-1]='0';

        }
        return -1;
    }
};


int main()
{
    
    return 0;
}