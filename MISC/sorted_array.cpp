#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void vec(vector<int> vec1)
{

    set<int>set1;

    for(int i=0;i<vec1.size();i++)
    {
        int r;
        cin>>r;
        set1.insert(r);
    }

    int arr[set1.size()];
    set<int>::iterator itr;
   itr=set1.begin();
    for(int i=0;i<vec1.size();i++)
    {
        if(i<vec1.size()){
        vec1[i]=*itr;
        itr++;
        }
        else{
            vec1[i]=0;
        }
    }

    for(int i=0;i<vec1.size();i++)
        cout<<vec1[i]<<" ";
}


int main()
{

    int n;
    cin>>n;

    vector<int>vec1;

    for(int i=0;i<n;i++)
    {
        int r;
        cin>>r;
        vec1.push_back(r);
    }

    sort(vec1.begin(),vec1.end());

    vec(vec1);


}
