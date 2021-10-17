class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int bsp=-prices[0];
        int ssp=0;
        for(int i=1;i<prices.size();i++)
        {   ssp=max(ssp,prices[i]-fee+bsp);
            bsp=max(bsp,ssp-prices[i]);
           
        }
        return ssp;
        
    }
};//O(n)