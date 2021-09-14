class Solution {
public:
    int numDecodings(string s) {
         int mod = 1e9+7;
    
    int n = s.size();
    vector<long long int> dp(n+1, 0);
    
    dp[n] = 1;
    if(s[n-1] == '*') dp[n-1] = 9 ;
    else if(s[n-1] == '0') dp[n-1] = 0;
    else dp[n-1] = 1;
    
    for(int i = n-2; i >= 0; i--){
        if(s[i] > '0' && s[i] != '*'){
            dp[i] = dp[i+1];
        }
        
        
        //when have to combine with 1 and 2.
        if(s[i] == '1' && s[i+1] == '*') dp[i] = (dp[i] + 9*dp[i+2])%mod;
        
        if(s[i] == '1' && s[i+1] != '*') dp[i] = (dp[i] + dp[i+2])%mod;
        
        if(s[i] == '2' && (s[i+1] < '7' && s[i+1] != '*')) dp[i] = (dp[i] + dp[i+2])%mod;
        
        if(s[i] == '2' && s[i+1] == '*') dp[i] = (dp[i] + 6*dp[i+2])%mod;
		
        //star case
        if(s[i] == '*'){
            // **
            if(s[i+1] == '*'){
                dp[i] = (dp[i] + 9*dp[i+1] + 9*dp[i+2] + 6*dp[i+2])%mod;
            }
			
            else{
                dp[i] = (dp[i] + 9*dp[i+1])%mod;
                if(s[i+1] < '7' && s[i+1] != '*') dp[i] = (dp[i] + dp[i+2])%mod;
                
                if(s[i+1] != '*')
                    dp[i] = (dp[i] + dp[i+2])%mod;
            }
        }
    }
    
    return dp[0];
        
    }
};