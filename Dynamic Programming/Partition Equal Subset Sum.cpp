class Solution {
public:
    bool subsetsum(vector<int>&nums,int w)
    { int n=nums.size();
     int dp[n+1][w+1];
     for(int i=0;i<=n;i++)
     {
         dp[i][0]=true;
     }
        for(int i=1;i<=w;i++)
     {
         dp[0][i]=false;
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=w;j++)
         { if(nums[i-1]>j)
         {
             dp[i][j]= dp[i-1][j];
         }
             else{
                 dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                 
             }
         }
     }
     return dp[n][w];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto a:nums)
        {
            sum+=a;
        }
        if(sum%2!=0)
        {
            return false;
        }
        else{
            sum=sum/2;
            return subsetsum(nums,sum);
        }
    }
};//O(N*SUM)