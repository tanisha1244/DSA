class Solution {
public:
    string longestPalindrome(string s) {
        string t=s;
        int n=s.length();
        int res=INT_MIN;
        string max;
        reverse(t.begin(),t.end());
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
               else if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    if(res<dp[i][j])
                    { string temp = s.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string revtemp = string(temp.rbegin(),temp.rend());
                        if(revtemp==temp)
                        {
                            res = dp[i][j] ;
                            max = temp ;
                        }
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        
        return max;
    }
};
      