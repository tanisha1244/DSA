class Solution {
public:
   
    
    int change(int amount, vector<int>& coins) {
         int dp[coins.size() + 1][amount + 1];
        
        for(int idx = 0; idx < coins.size() + 1; idx++)
            dp[idx][0] = 1;
        
        for(int idx = 1; idx < amount + 1; idx++)
            dp[0][idx] = 0;
        
        for(int row = 1; row < coins.size() + 1; row++)
        {  
            for(int col = 1; col < amount + 1; col++)
            {
                if(coins[row - 1] <= col)
                    dp[row][col] = dp[row][col - coins[row - 1]] + dp[row - 1][col];
                
                else
                    dp[row][col] = dp[row - 1][col];
            }
        }
        
        return dp[coins.size()][amount];
    }
};