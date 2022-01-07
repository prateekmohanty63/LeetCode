#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>vec1;
    int profit=0;

    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        vec1.push_back(r);
    }

    /// BEST TIME TO BUY AND SELL STOCKS
    int minim=9999999;
    for(int i=0;i<n;i++){
      mini=min(mini,vec1[i]);
      profit=max(profit,vec1[i]-mini);

    }

    /// BEST TIME TO BUY AND SELL STOCKS II


}
