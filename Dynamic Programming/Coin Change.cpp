class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int Max =  INT_MAX;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i&& dp[i-coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == Max ? -1 : dp[amount];   
        
        
    }
};