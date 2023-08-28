class Solution {
public:
    int arrangeCoins(int n) {
        int k=0;
        int count=0;
        while(n){
            if(k<n){
                k++;
                n-=k;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};
