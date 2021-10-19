class Solution {
public:
     int superEggDrop(int K, int N) {
       vector<vector<int>>dp(K+1,vector<int>(N+1,-1));
       return solve(K,N,dp);
    }
    
   
    int solve(int eggs,int floors,vector<vector<int>> &dp)
    {
        if(dp[eggs][floors]!=-1)
            return dp[eggs][floors];
        else if(eggs==0 || floors==0)
            return dp[eggs][floors]=0;
        else if(floors==1)
            return dp[eggs][floors]=1;
        else if(eggs==1)
            return dp[eggs][floors]=floors;
        else
        {
          int l=1,h=floors;
          int minn=INT_MAX;
          while(l<=h)                         
          {
              int mid=l+(h-l)/2;
              int a=solve(eggs-1,mid-1,dp);
              int b=solve(eggs,floors-mid,dp);
              int x=max(a,b);
              minn=min(minn,x+1);
              if(a>b)
                  h=mid-1;
              else
                  l=mid+1;
          }
         dp[eggs][floors]=minn;   
        }  
        return dp[eggs][floors];}
};//O(E*F)