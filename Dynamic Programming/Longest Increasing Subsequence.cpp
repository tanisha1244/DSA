class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int maxi2=0;
        for(int i=0;i<n;i++)
        { int maxi=0;
            for(int j=0;j<=i;j++)
            {
                if(nums[j]<nums[i])
                {
                    maxi=max(maxi,dp[j]);
                }
            }
            dp[i]=maxi+1;
         maxi2=max(maxi2,dp[i]);
        }
        return maxi2; 
        
        
    }
};//O(N*N)