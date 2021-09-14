class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool iscyclics(vector<bool>&vis,vector<bool>&visre,int i,vector<int>adj[] )
    {
        if(vis[i]==false)
        {
            vis[i]=visre[i]=true;
            for(auto it:adj[i])
            {
                if(!vis[it]&&iscyclics(vis,visre,it,adj))
                {
                    return true;
                }
                else if(visre[it])
                {
                    return true;
                }
            }
        }
        visre[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false);
        vector<bool>visre(V,false);
        for(int i=0;i<V;i++)
        {
            if(iscyclics(vis,visre,i,adj))
             {
                 return true;
             }
        }
        return false;
    }
};
