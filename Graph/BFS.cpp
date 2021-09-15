#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<int>vis(V,0);
        vector<int>v;
        vis[0]=1;
        q.push(0);
        while(!q.empty())
        {
            for(int i=0;i<q.size();i++)
            {
                int t=q.front();
                q.pop();
                for(auto it:adj[t])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
                v.push_back(t);
            }
        }
        return v;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  