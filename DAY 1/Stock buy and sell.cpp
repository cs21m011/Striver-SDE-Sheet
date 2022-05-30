class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],profit=0;
        
        for(int i=1;i<prices.size();i++){
            //finding best day to buy
            if(prices[i]<buy)
                buy=prices[i];
            //finding the best day to sell
            else if(prices[i]>buy){
                if(prices[i]-buy>profit)
                    profit=prices[i]-buy;
            }
        }
        return profit;
    }
};