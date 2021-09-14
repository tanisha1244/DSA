class Solution {
public:
  int painthouse(vector<vector<int>>&cost){
           int n=cost.size();
           int dp[n][3];
           for(int i=0;i<3;i++){dp[0][i]=cost[0][i];}
           for(int i=1;i<n;i++)
                 {
                    dp[i][0]=cost[i][0]+min(dp[i-1][1],dp[i-1][2]);
                    dp[i][1]=cost[i][1]+min(dp[i-1][0],dp[i-1][2]);
                    dp[i][2]=cost[i][2]+min(dp[i-1][1],dp[i-1][0]);
                  }
          return min(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
        }
};