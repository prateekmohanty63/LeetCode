#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// 1.minimum string left
class Solution {
public:
    int minimizedStringLength(string s) {
        
        int n=s.length();
        
       vector<char>vec;
        unordered_map<char,bool>mp;
        
        
        for(int i=0;i<n;i++)
        {
            char currChar=s[i];
            if(mp.find(currChar)==mp.end())
            {
                vec.push_back(currChar);
                mp[currChar]=true;
            }
        }
        return mp.size();
    }
};

// 2. Semi-Ordered Permutation
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        if(nums[0]==1 && nums[n-1]==n)return 0;
        
        int pos1=-1;
        int posn=-1;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)pos1=i;
            
            if(nums[i]==n)posn=i;
        }
        
        if(pos1<posn)return (pos1-0)+((n-1)-posn);
        
        else{
            return (pos1-0)+((n-1)-posn)-1;
        }
        
    }
};


// 3. Sum of Matrix After Queries

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        long long sum=0;
        
        unordered_map<int,bool>colTaken,rowTaken;
        
        int rowLeft=n;
        int colLeft=n;
        
        // we start from behind , as the value inserted in any row or column will be be final value of that row or column from the end
        
        for(int i=queries.size()-1;i>=0;i--)
        {
            int type=queries[i][0];
            int index=queries[i][1];
            int val=queries[i][2];
            
            if(type==0)
            {
                if(rowTaken.find(index)==rowTaken.end()){

                sum+=(rowLeft*val);
                rowTaken[index]=true;
                
                // we decrement the column-left value 
                    colLeft--;
            }
         }
            else{
                
                if(colTaken.find(index)==colTaken.end())
                {
                    sum+=(colLeft*val);
                    colTaken[index]=true;
                    
                    // we decrement the row-left value
                    rowLeft--;
                }
                
            }
        }
        return sum;
    }
};



int main()
{
    
    return 0;
}