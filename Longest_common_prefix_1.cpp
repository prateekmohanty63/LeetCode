#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string prefix(vector<string> vec1)
{
    sort(vec1.begin(),vec1.end());

    string a=vec1[0];

    string b=" ";
    vector<int>vec2;


    for(int i=1;i<vec1.size();i++)
    {
        int count=0;
        for(int j=0;j<a.size();j++)
        {
            if(vec1[0][j]==vec1[i][j])
            {
                count++;
            }
            else{
                break;
            }
        }
        vec2.push_back(count);

    }

    sort(vec2.begin(),vec2.end());

    int min_pos=vec2[0];

    if(min_pos==0){
        return b;
    }

    else{
        for(int i=0;i<min_pos;i++)
        {
            b+=a[i];
        }

    }
    return b;
}

int main()
{
    vector<string> vec3;

    string a;

    for(int i=0;i<3;i++)
    {
        cin>>a;
        vec3.push_back(a);
    }
    cout<<prefix(vec3);
}
