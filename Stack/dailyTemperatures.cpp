#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();

        vector<int>res(n,0);

        stack<int>tempInd;
        tempInd.push(n-1);

        for(int i=n-2;i>=0;i--)
        {
            while(!tempInd.empty() && temperatures[tempInd.top()]<=temperatures[i])
            {
                tempInd.pop();
            }

            if(!tempInd.empty())
            {
                res[i]=tempInd.top()-i;
            }

            tempInd.push(i);
        }

        return res;
    }
};


int main()
{
    
    return 0;
}