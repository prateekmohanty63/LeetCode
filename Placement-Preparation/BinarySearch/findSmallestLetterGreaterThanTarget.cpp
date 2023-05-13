#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:

    char binSearch(vector<char>&letters,char target)
    {
        int n=letters.size();
        int start=0;
        int end=letters.size()-1;
        char closestChar=letters[0];
        int closestDiff=INT_MAX;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(letters[mid]==target)
            {
                if(mid+1<n && letters[mid+1]!=letters[mid])return letters[mid+1];
               else start=mid+1;
                
            }
            else if(target>letters[mid])
            {   

                start=mid+1;
            }
            else{
                if(letters[mid]-target<=closestDiff)
                {
                    closestDiff=letters[mid]-target;
                    closestChar=letters[mid];
                }
                end=mid-1;
            }
        }
        return closestChar;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char res=binSearch(letters,target);

        return res;
    }
};

int main()
{
    
    return 0;
}