class Solution {
public:
void dfs(int i, vector<int>adj[],vector<int>&vis)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis);
        }
    }
}
 bool connected(int V, vector<int>adj[])
 {
     vector<int>vis(V+1,0);
     int node=-1;
     for(int i=0;i<V;++i)
     {
         if(adj[i].size()>0)
         {
             node=i;
             break;
         }
     }
     if(node==-1)
        {return true;}
     dfs(node,adj,vis);
    for(int i=0;i<V;i++)
    {
        if(!vis[i]&&adj[i].size()>0)
        {
            return false;
        }
    }
    return true;
     
 }
	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	    if(!connected(V,adj))
	          {return 0;}
	  int odd=0;
	  for(int i=0;i<V;++i)
	  {
	      if(adj[i].size()&1)
	      {
	          odd=odd+1;
	      }
	  }
	  if(odd > 2)
		return 0;

    	return (odd==0)?2:1;
	 
	}
};