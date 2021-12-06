class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX,profit=0;
        for(auto i:prices){
            mn=min(mn,i);
            profit=max(profit,i-mn);
        }
        return profit;
    }
};
