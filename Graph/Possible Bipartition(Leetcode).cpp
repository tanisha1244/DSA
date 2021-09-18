class Solution {
public:
    bool cyclic(int i,int n, vector<vector<int>> &adj,vector<int> &color)
    {
        color[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(int  it:adj[t])
            {  if(color[it]==color[t])
                {
                    return false;
                }
                
                if(color[it]==-1)
                {
                    color[it]=1-color[t];
                    q.push(it);
                }
                
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();++i)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
            
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;++i)
        {
            if(color[i]==-1)
            { if(!cyclic(i,n,adj,color))
            {
                return false;
            }
             }
        }
        return true;
        
    }
};