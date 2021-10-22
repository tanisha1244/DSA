class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
       vector<vector<int>>dp(n+1,vector<int>(n+1));
       for(int i=0;i<=n;i++)
         {
             
             for(int j=0;j<=n;j++)
             {
                 if(i==0||j==0)
                 {
                     dp[i][j]=0;
                 }
                 else if(i>j)
                 {
                     dp[i][j]=dp[i-1][j];
                 }
                 else{
                     dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i]);
                    }
             }
         }
         return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends