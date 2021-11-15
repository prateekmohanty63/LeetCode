class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int flag=0;int flag1=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1])
                flag=1;
            if(prices[i]>prices[i+1])
                flag1=1;
        }

        if(flag==0)
            return 0;
        if(flag1==0)
            return prices[prices.size()-1]-prices[0];

       //// Here we apply the logic that we buy when we get a local minima
       //// and we sell when we get a local maxima

        int profit=0,i=0,n=prices.size();

        while(i<n-1){
            while((i+1!=n) && (prices[i]>=prices[i+1]))
                i++;
            profit-=prices[i];

            while((i+1!=n) && (prices[i]<prices[i+1]))
                i++;
            profit+=prices[i];
        }
        return profit;
    }
};
