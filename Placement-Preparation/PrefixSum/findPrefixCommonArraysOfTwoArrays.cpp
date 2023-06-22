#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n=A.size();
        
        vector<int>res(n,0);
        
        unordered_map<int,bool>arrA,arrB;
        
        if(A[0]==B[0])res[0]=1;
        
        arrA[A[0]]=true;
        arrB[B[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            int currCount=res[i-1];
            
            if(A[i]==B[i])currCount+=1;
            
            else{
                // check if element of A exists in B
                if(arrB.find(A[i])!=arrB.end())currCount+=1;
                
                // check if element of B exists in A
                if(arrA.find(B[i])!=arrA.end())currCount+=1;
                
                
            }
            arrA[A[i]]=true;
            arrB[B[i]]=true;
            
            res[i]=currCount;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}