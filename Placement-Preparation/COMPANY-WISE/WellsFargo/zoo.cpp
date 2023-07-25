#include<iostream>
#include<vector>
using namespace std;

int main()
{  
    int n;
    cin>>n;

    vector<int>vec;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }
    
    return 0;
}