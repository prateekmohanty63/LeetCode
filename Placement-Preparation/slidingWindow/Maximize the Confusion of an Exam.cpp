#include<iostream>
#include<climits>
using namespace std;

// T(N)=O(N)
// S(N)=O(1)

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int start=0;
        int end=0;
        int n=answerKey.size();

        int trueCount=0;
        int falseCount=0;
        int res=INT_MIN;
        int minimVal=INT_MAX;

        while(end<n)
        {
            if(answerKey[end]=='T')trueCount++;
            else falseCount++;

            minimVal=min(trueCount,falseCount);
            
            if(minimVal<=k)
            {
                res=max(res,end-start+1);
            }
            else{
                while(start<end && minimVal>k)
                {
                    if(answerKey[start]=='T')trueCount--;
                    else falseCount--;
                    minimVal=min(trueCount,falseCount);
                    start++;
                }
            }
             end++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}