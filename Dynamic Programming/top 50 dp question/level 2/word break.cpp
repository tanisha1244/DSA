class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.length();
        unordered_set<string>s(B.begin(),B.end());
        vector<bool>dp(n+1,false);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            string r="";
            for(int j=i;j<n;j++)
            {
                r=r+A[j];
                if(s.find(r)!=s.end())
                {
                    dp[i]=dp[i]||dp[j+1];
                }
            }
        }
        return dp[0];
    }
};
