#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        
        string compressedString;
        vector<char>res;

        int n=chars.size();


        for(int i=0;i<n-1;i++)
        {
            if(chars[i]!=chars[i+1])
            {
                compressedString+=chars[i];
            }
            else{
                int k=i;
                int count=0;
                char a=chars[i];

                while(k<n && chars[k]==a)
                {
                    k++;
                    count++;
                }
                string e=to_string(count);
                compressedString+=a;
                compressedString+=e;
                i=k-1;
            }
        }

     if(compressedString.length()==0)return 1;

     if(chars[n-2]!=chars[n-1]){
            compressedString+=chars[n-1];
        }
     
     cout<<compressedString.length();


    for(int i=0;i<compressedString.length();i++){
        chars[i]=compressedString[i];
    }
     return compressedString.length();

    }
};

int main()
{
    
    return 0;
}