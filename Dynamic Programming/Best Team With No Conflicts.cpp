class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<ages.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        
        
        sort(v.begin(),v.end());
        
        int n=v.size();
        int dp[n + 1];
        int ans=INT_MIN;
        
      for(int i=0;i<n;i++){
          dp[i]=v[i].second;
          ans=max(ans,dp[i]);
      }
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                
                    if(v[i].second>=v[j].second and dp[j] + v[i].second>dp[i]){
                        dp[i]=dp[j] + v[i].second;
                        ans=max(ans,dp[i]);
                    }
                
            }
        }
        
        return ans;
        
    }
};//O(NLOGN + N^2)