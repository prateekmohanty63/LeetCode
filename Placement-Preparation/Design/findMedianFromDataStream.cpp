#include<iostream>
#include<vector>
using namespace std;

// TLE
class MedianFinder {
public:
   vector<int>vec;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(vec.size()==0)
        vec.push_back(num);

        else{
            int n=vec.size();

            if(n==1)
            {
                if(vec[0]<=num)
                vec.push_back(num);

                else vec.insert(vec.begin()+0,num);
            }
            else{
                int start=0;
                int end=1;
                int flag=0;
                int n=vec.size();
                
                if(vec[0]>=num)
                vec.insert(vec.begin()+0,num);
                
                else{
                while(end<n)
                {
                   int first=vec[start];
                   int second=vec[end];
                   if(first<=num && num<=second)
                   {
                       vec.insert(vec.begin()+end,num);
                       flag=1;
                       break;
                   }
                   start++;
                   end++;
                }
                if(flag==0)
                vec.push_back(num);
                }

            }
          //  for(auto it:vec)cout<<it<<" ";
            // cout<<endl;
        }
    }
    
    double findMedian() {
        
        int n=vec.size();
        

        if(n%2==1)
        {
            return vec[n/2];
        }
        else{
            double res=0;
            int num=vec[n/2];
            int num1=vec[(n/2)-1];
            res=(double)(num+num1)/(double)2;
             return res;
        }

       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    
    return 0;
}