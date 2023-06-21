#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


// KMP in leetcode (accepted)

class Solution {
public:
    vector<int> preFix(string a)
    {
        int n=a.size();
        vector<int>preFixArr(n,0);

        for(int i=1;i<n;i++)
        {
            int j=preFixArr[i-1];

            while(j>0 && a[i]!=a[j])j=preFixArr[j-1];

            if(a[i]==a[j])j++;

            preFixArr[i]=j;
        }
        return preFixArr;
    }

    int kmp(string input,string pattern)
    {
        int pos=-1;
        int n=input.length();
        int m=pattern.length();

        int i=0,j=0;

        vector<int>pre=preFix(pattern);

        while(i<n)
        {
            if(input[i]==pattern[j])
            {
                i++;
                j++;
            }
            else{
                if(j!=0)j=pre[j-1];

                else i++;
            }

            if(j==m)
            {
                // match found
                pos=i-pattern.size();
                break;
            }
        }
        return pos;
    }
    int strStr(string haystack, string needle) {

        if(haystack==needle)return 0;

        return kmp(haystack,needle);


    }
};

vector<int> prefix_function(string s)
{
	int n=s.size();
	vector<int>pi(n,0);

	for(int i=1;i<n;i++){
		int j=pi[i-1];

		while(j>0 && s[i]!=s[j])j=pi[j-1];
        
		// s[0..i-1]=ab..ab 
		// pi[i-1]=2
		// s[0..i]=abc.abc
		// pi[i]=j++
		if(s[i]==s[j])j++;

		pi[i]=j;
	}
    
	// Time complexity = O(n)
	return pi;
}

int main()
{   

	string pattern="abcabcd";

	vector<int>prefix=prefix_function(pattern);

	for(auto it:prefix)cout<<it<<" ";

	cout<<endl;

	// now we can implement the actual algo
    
	string inp="abcerdadaabcabcd";

	int pos=-1;
	int i=0,j=0;

	while(i<inp.size()){
		if(inp[i]==pattern[j]){
			j++;
			i++;
		}
		else{
			if(j!=0)j=prefix[j-1];

			else i++;
		}
		if(j==pattern.size()){
			pos=i-pattern.size();
			break;
		}
	}
   cout<<"Found at index: "<<" "<<pos;
	return 0;
}