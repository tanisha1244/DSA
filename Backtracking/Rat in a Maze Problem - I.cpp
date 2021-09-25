class Solution{
    public:
    vector<string>pathlen;
    string path;
  
    void dfs(int r,int c,int n,vector<vector<int>> m, vector<vector<bool>> &vis)
    {
        if(r<0||r>=n||c<0||c>=n||vis[r][c]||m[r][c]==0)
        { path.pop_back();
            return;
        }
        
        vis[r][c]=true;
        
        path.push_back('L');
        dfs (r, c-1,n,m, vis);   
        path.push_back('U');
        dfs (r-1, c,n,m, vis);
        path.push_back('R');
        dfs (r, c+1,n,m, vis);
        path.push_back('D');
        dfs (r+ 1, c,n,m, vis);
        if(r==n-1&&c==n-1)
        {
            pathlen.push_back(path);
        }
        path.pop_back();
        
        vis[r][c]=false;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       vector<vector<bool>>vis(n,vector<bool>(n,false));
       dfs(0,0,n,m,vis);
       sort(pathlen.begin(),pathlen.end());
       return pathlen;
    }
};

    