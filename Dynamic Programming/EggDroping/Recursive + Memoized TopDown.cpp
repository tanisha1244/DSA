class Solution {
public:
    //Time: O(n^2*k), Space: O(n*k)
    int helper(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX;
        
        for(int i=1; i<=n; i++){
            
            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            int temp = 1 + max(helper(k-1, i-1, memo), helper(k, n-i, memo));
            
            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        //k means number of eggs, n means number of floors
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return helper(k, n, memo);
    }
};