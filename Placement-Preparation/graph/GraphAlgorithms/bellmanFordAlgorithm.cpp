#include<iostream>
#include<vector>
using namespace std;

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	   
	    
	    int inf=100000000;
	    vector<int>dist(n,inf);
	    
	    // relaxing N-1 times
	    for(int i=1;i<=n-1;i++)
	    {
	        for(auto it:edges)
	        {
	            int u=it[0];
	            int v=it[1];
	            int weight=it[2];
	            
	            if(dist[u]+weight<dist[v])
	            {
	                dist[v]=dist[u]+weight;
	            }
	        }
	    }
	    
	    for(auto it:edges)
	    {
	        int u=it[0];
	        int v=it[1];
	        int weight=it[2];
	        
	        if(dist[u]+weight<dist[v])return true;
	    }
	    return false;
	}

int main()
{
    
    return 0;
}