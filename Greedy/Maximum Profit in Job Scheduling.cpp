class Solution {
public:
    int jobScheduling(vector<int>&s, vector<int>& e, vector<int>& p) {
         int n = s.size();
        vector<vector<int>>v(n,vector<int>(3));
        for(int i=0;i<n;i++)
            v[i] = {e[i],s[i],p[i]};
        sort(v.begin(),v.end());
        vector<int>dp(n,0);
        dp[0]=v[0][2];
        for(int i=1;i<n;i++)
        {
            int last=-1;
            int inc=v[i][2];
            int exc=dp[i-1];
            int k=0;
            int l=i-1;
            while(k<=l)
            {
                int mid=k+((l-k)/2);
                if(v[mid][0]<=v[i][1])
                {
                    last=mid;
                    k=mid+1;
                }
                else{
                    l=mid-1;
                }
            }
            if(last!=-1){inc=inc+dp[last];}
            dp[i]=max(inc,exc);
           
        }
        return dp[n-1];
    }
};