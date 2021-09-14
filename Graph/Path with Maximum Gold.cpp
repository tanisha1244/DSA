class Solution 
{
public:
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j] || vis[i][j])
        {
            return 0;
        }
        vis[i][j]=true;
        int left=helper(grid,i,j-1,vis);
        int right=helper(grid,i,j+1,vis);
        int up=helper(grid,i-1,j,vis);
        int down=helper(grid,i+1,j,vis);
        vis[i][j]=false;
        return grid[i][j]+max(left,max(right,max(up,down)));
    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int ans=0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    ans=max(ans,helper(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
};