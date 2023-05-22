#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;

        int n=expression.length();

        for(int i=0;i<n;i++)
        {
            char cur=expression[i];

             // we will split the string at the operand 
            if(cur=='+' || cur=='*' || cur=='-')
            {
                vector<int>vec=diffWaysToCompute(expression.substr(0,i));
                vector<int>vec1=diffWaysToCompute(expression.substr(i+1));

                for(auto it:vec)
                {
                    for(auto it1:vec1)
                    {
                        if(cur=='+')
                        {
                            res.push_back(it+it1);
                        }
                        else if(cur=='-')
                        res.push_back(it-it1);

                        else res.push_back(it*it1);
                    }
                }
            }
        }
                // if the input string contains only number
        if (res.empty())
            res.push_back(atoi(expression.c_str()));

        //if(res.empty())return res.push_back(atoi(expression.c_str()));
        return res;
    }
};

int main()
{
    
    return 0;
}