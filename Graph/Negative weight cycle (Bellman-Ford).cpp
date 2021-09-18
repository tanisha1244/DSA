#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dis(n,INT_MAX);
	    dis[0]=0;
	    for(int i=1;i<=n-1;i++)
	    { 
	        for(auto it:edges)
	        { int x=it[0];
	        int y=it[1];
	        int w=it[2];
	            if(dis[x]!=INT_MAX&&dis[y]>dis[x]+w)
	            {
	                dis[y]=dis[x]+w;
	            }
	        }
	    }
	        int f=0;
	   for(auto it:edges)
	        { int x=it[0];
	        int y=it[1];
	        int w=it[2];
	            if(dis[x]!=INT_MAX&&dis[y]>dis[x]+w)
	            {
	                f=1;
	                break;
	            }
	        }
	        if(f==1)
	        {
	            return 1;
	        }
	            return 0;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends