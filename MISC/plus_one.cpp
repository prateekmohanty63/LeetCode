#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;


int main()
{

    vector<int>vec1;

    int n;
    cin>>n;
    int r;


    for(int i=0;i<n;i++)
    {
        cin>>r;
        vec1.push_back(r);
    }

       long long int count=0;

    for(int i=0;i<n;i++)
    {
        count+=vec1[i]*pow(10,vec1.size()-i-1);
    }

    count++;

    string a=to_string(count);

    vector<int> vec2;

    int e=a.length();

    long long int k=stoi(a);
    int temp=k;

    for(int i=0;i<e;i++)
    {
        vec2.push_back(temp%10);
        temp/=10;
    }

    reverse(vec2.begin(),vec2.end());

    for(int i=0;i<vec2.size();i++)
        cout<<vec2[i];

}
