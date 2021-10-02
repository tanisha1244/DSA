class Solution {
public:
   void subsetsum(vector<int>nums,vector<vector<bool>>&dp,int t)
   { int n=nums.size();
       for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
       
        for(int i=0;i<=t;i++)
        {
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=t;j++)
            {  if(nums[i-1]>j)
                   {dp[i][j]=dp[i-1][j];}
               
               else{
                   dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                    }
            }
        }
   }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        int t=sum/2;
         vector<vector<bool>> dp( n+1 , vector<bool> (t+1));
        subsetsum(nums,dp,t);
        return dp[n][t];
        
        
    }
}; //TC:O{SUM*N)
   //SC:O(SUM*N)
    //TC:O(2^N) FOR RECURSIVE CODE