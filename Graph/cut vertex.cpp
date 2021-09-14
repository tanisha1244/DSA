#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int parent , vector<int>&vis, vector<int>&tin,vector<int>&low,int timer,vector<int> adj[], vector<int>&isArticulation)
{
	vis[i]=1;
	tin[i]=low[i]=timer++;
	int child=0;
	for(auto it:adj[i])
	{
		if(it==parent)continue;
		if(!vis[it])
		{
			dfs(it,i, vis, tin, low, timer, adj, isArticulation); 
			low[i]=min(low[it],low[i]);
			child++; 
			if(low[it]>=tin[i] && parent!=-1)
			{
				
				isArticulation[i]=1;
			}
		}else{
			low[i]=min(tin[it],low[i]);
		}
		
	}
	if(child>1 &&parent!=-1)
	{
		isArticulation[i]=1;
	}
}



int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}

