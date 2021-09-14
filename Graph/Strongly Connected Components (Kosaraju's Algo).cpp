class Solution
{ 
	public:
	//Function to find number of strongly connected components in the graph.
     unordered_map<int,vector<int>>rev;
	 void dfs(int i, vector<int> adj[],stack<int>&s, vector<bool>&vis)
	 {
	     vis[i]=true;
	     for(auto j:adj[i])
	     { if(!vis[j]){
	         dfs(j,adj,s,vis);}
	     }
	     s.push(i);
	 }
	 void reverse(int v,vector<int> adj[])
	 {
	     for(int i=0;i<v;i++)
	     {
	       for(auto j:adj[i]) 
	       {
	           rev[j].push_back(i);
	       }
	     }
	 }
	 void dfs2(int i, vector<bool>&vis)
	 {
	     vis[i]=true;
	     for(auto j:rev[i])
	     { if(!vis[j]){
	         dfs2(j,vis);}
	     }
	 }
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int>s;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,s,vis);
            }
        }
         
        reverse(V,adj);
        for(int i=0;i<V;i++)
        {
            vis[i]=false;
        }
        int c=0;
        while(!s.empty())
        {
            int k=s.top();
            s.pop();
            if(!vis[k])
            {
            dfs2(k,vis);
            c++;
           }
        }
        return c;
        
    }
};