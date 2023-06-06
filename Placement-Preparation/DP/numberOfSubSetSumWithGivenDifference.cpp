#include<iostream>
using namespace std;

#include<iostream>
#include<vector>

using namespace std;

int noSubSets(vector<int>&arr,int i,int sum,int &sumToFind)
{
    // base case
    if(sum==sumToFind)return 1;
    
    if(i>=arr.size())return 0;
    
    // we have the option of taking the element in the subset or not taking it 
    
    return noSubSets(arr,i+1,sum+arr[i],sumToFind)+noSubSets(arr,i+1,sum,sumToFind);
}

int main() {
	//code
	
	
	vector<int>arr={1,2,3,1,2};
	int n=arr.size();
	
	int totalSum=0;
	int diff=1;
	
	for(int i=0;i<n;i++)totalSum+=arr[i];
	
	// let sum1=x 
	// let sum2=y 
	// sum1+sum2=totalSum
	// sum1-sum2=diff 
	// sum1=(totalSum+dff)/2
	
	int sumToFind=(totalSum+diff)/2;
	
	cout<<noSubSets(arr,0,0,sumToFind);
	
	return 0;
}

int main()
{
    
    return 0;
}