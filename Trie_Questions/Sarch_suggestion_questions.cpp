#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// this is brute force method
// Runtime: 1397 ms, faster than 7.13% of C++ online submissions for Search Suggestions System.
// Memory Usage: 332 MB, less than 11.41% of C++ online submissions for Search Suggestions System.
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>>res;
        
        sort(products.begin(),products.end());
        
        int n=products.size();
        int m=searchWord.size();
        
        for(int i=0;i<n;i++)
            cout<<products[i]<<" ";
        
        string wordPre;
        int k=1;
        
        for(int i=0;i<m;i++)
        {
             int l=0;
            wordPre+=searchWord[i];
            vector<string>vec1;
            for(int j=0;j<n;j++)
            {
                if(l==3)break;
                
                string str=products[j];
                string str1=str.substr(0,k);
                if(str1==wordPre)
                {
                    vec1.push_back(str);
                    l++;
                }
                
                
            }
            
            k++;
            res.push_back(vec1);
        }
        
        
        
        return res;
    }
};

int main()
{
    
    return 0;
}