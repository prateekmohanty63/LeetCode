#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>res;
        
        int n=arr.size();
        
        int closeEle;
        int minim=INT_MAX;
        int closeIndex;
        
        // finding the closest element to x
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i]-x)<minim)
            {
                minim=abs(arr[i]-x);
                closeIndex=i;
                closeEle=arr[i];
            }
           
        }
        //res.push_back(arr[closestIndex]);
        
        int index=closeIndex;
        
        // pushing all the elements having the closest difference
        while(k>0 && index<n && abs(arr[index]-x)==minim)
        {
            res.push_back(arr[index]);
            index++;
            k--;
        }
        
        
        // lower value points to the index previous to the first lower value
        int lower=closeIndex-1;
        
        // higher points to the next element of the current index
        int higher=index;
        
        
        
        while(k>0)
        {
          
            int lowerValue=INT_MAX;
            int upperValue=INT_MAX;
            
            if(lower>=0)
           lowerValue=abs(arr[lower]-x);
        
            
            if(higher<n)
            upperValue=abs(arr[higher]-x);
            
                
            
            // push whichever value is closer to x
            
            if(lower>=0 && lowerValue<upperValue)
            {
                res.push_back(arr[lower]);
                lower--;
                 k--;
            }
            else if(higher<n && upperValue<lowerValue)
            {
                res.push_back(arr[higher]);
                higher++;
                 k--;
            }
            else if(upperValue == lowerValue)
            {
                res.push_back(arr[lower]);
                lower--;
                k--;
            }
            else break;
         
            
        }
        
        // if k still not 0 push higher elements to res
        while(k>0 && higher<n)
        {
            res.push_back(arr[higher++]);
            k--;
        }
        
        // if k still not 0 push higher elements to res
         while(k>0 && lower>=0)
        {
            res.push_back(arr[lower--]);
             k--;
        }
        
        
       // cout<<minim;
        
        sort(res.begin(),res.end());
        
        return res;
    }
};

int main()
{
    
    return 0;
}