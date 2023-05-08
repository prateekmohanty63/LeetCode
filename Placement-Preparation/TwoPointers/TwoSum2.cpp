#include<iostream>
#include<vector>
using namespace std;



// Two pointer approach
// T(N):O(n)
// S(N):O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int>res;

        int n=numbers.size();

        int ptr1=0;
        int ptr2=n-1;

        while(ptr1<ptr2)
        {
            int sum=numbers[ptr1]+numbers[ptr2];

            if(sum==target)
            {
                res.push_back(ptr1+1);
                res.push_back(ptr2+1);
                return res;
            }
            else if(sum<target)
            {
                ptr1++;
            }
            else ptr2--;
        }
        return res;
    }
};


// Binary search algorithm
// T(N):O(nlogn)
// S(N):O(1)

class Solution {
public:
  
  int binSearch(vector<int>&vec,int target,int &ind,int start,int end)
  {
      if(start<=end)
      {
          int mid=start+(end-start)/2;

          if(vec[mid]==target && mid!=ind)return mid;

          if(vec[mid]==target && mid==ind)
          {
              if(mid+1<vec.size() && vec[mid+1]==target)return mid+1;

              if(mid-1>=0 && vec[mid-1]==target)return mid-1;

              else return -1;
          }

          else if(target>vec[mid])return binSearch(vec,target,ind,mid+1,end);

          else return binSearch(vec,target,ind,start,mid-1);
      }
      return -1;
  }

    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int>res;
        int n=numbers.size();

        for(int i=0;i<numbers.size();i++)
        {
            int ind=binSearch(numbers,target-numbers[i],i,0,n-1);

            if(ind!=-1)
            {
                res.push_back(i+1);
                res.push_back(ind+1);
                return res;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}