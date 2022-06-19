#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// most optimized method
// Runtime: 51 ms, faster than 91.34% of C++ online submissions for Search Suggestions System.
// Memory Usage: 26.3 MB, less than 85.68% of C++ online submissions for Search Suggestions System.
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& product, string searchWord) {
        
        vector<vector<string>>res;
        
        sort(product.begin(),product.end());
        
        int n=product.size();
        int m=searchWord.size();
        int l=0,r=product.size()-1;
      
        
        for(int i=0;i<m;i++)
        {
              
            vector<string>vec1;
            char c=searchWord[i];
            
            while(l<=r && (product[l].size()<=i || product[l][i]!=c))
            {
                l++;
            }
            while(l<=r && (product[r].size()<=i || product[r][i]!=c))
            {
                r--;
            }
            int numberValid=r-l+1;
        
            
            if(numberValid>3)numberValid=3;
           int k=0;
            
            while(numberValid!=0)
            {
                vec1.push_back(product[l+k]);
                numberValid--;
                k++;
            }
            res.push_back(vec1);
        }
       
        
        
        
        return res;
    }
};
// Optimized version of brute force mechanism
// Runtime: 631 ms, faster than 17.07% of C++ online submissions for Search Suggestions System.
// Memory Usage: 194.4 MB, less than 12.94% of C++ online submissions for Search Suggestions System
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
        int begin=0;
        
        for(int i=0;i<m;i++)
        {
             int l=0;
            wordPre+=searchWord[i];
            vector<string>vec1;
            for(int j=begin;j<n;j++)
            {
                if(l==3)break;
                
                string str=products[j];
                string str1=str.substr(0,k);
                if(str1==wordPre)
                {
                    if(l==0)
                    {
                        begin=j;
                    }
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