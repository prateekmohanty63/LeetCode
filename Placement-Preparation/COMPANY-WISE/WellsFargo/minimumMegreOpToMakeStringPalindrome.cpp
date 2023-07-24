#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int>vec;
   

    int n;
    cin>>n;

     vector<int>res(n,-1);

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
      
    }

    int start=0;
    int end=n-1;
    int count=0;

    while(start<=end)
    {
        if(vec[start]==vec[end])
        {
           
            start++;
            end--;
        }
        else if(vec[start]<vec[end])
        {   
           
            count++;
            vec[start+1]+=vec[start];
            vec[start]=-1;
            start++;

        }
        else{
            
             count++;
            vec[end-1]+=vec[end];
            vec[end]=-1;
            end--;
        }
    }

    cout<<count;
    cout<<endl;

    for(auto it:vec)
    {
        if(it!=-1)cout<<it<<" ";
    }
    return 0;
}