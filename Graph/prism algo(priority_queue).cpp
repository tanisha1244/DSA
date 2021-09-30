#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int sum=0;
        int level=0;
        q.push({0,0});
         vector<bool> vis(V, false);
        while(!q.empty())
        {
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
            if(vis[node]==true){continue;}
            vis[node]=true;
            level++;
            sum+=dis;
            if(level==V)
            {
                return sum;
            }
           for (int i=0; i<adj[node].size(); i++)
            { if(!vis[adj[node][i][0]]){
                q.push({adj[node][i][1],adj[node][i][0]});}
            }
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}