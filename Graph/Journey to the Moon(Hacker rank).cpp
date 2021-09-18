#include<bits/stdc++.h>

using namespace std; 


int main()
{ 
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    queue < int > q;
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    long long result = 1;
    
    vector<int> visited(N);
    for(int i=0;i<N;i++)
        {
        visited[i]=0;
    }
    
    for(int i=0;i<N;i++)
        {long long ans=0;
        if(!visited[i])
            {
            ans=1;
            q.push(i);
            visited[i]=1;
            while(!q.empty())
	           {
	           	int node = q.front();
	           	q.pop();
                int l=pairs[node].size();
	           	for(int j =0 ; j<l;j++)
	           	{
		    	int next = pairs[node][j];
			     if(!visited[next])
			     {
				 visited[next]=1;
				q.push(next); 
                     ans++;
			     }
		      }
	       }
        }
        result=result+(ans*(N-ans));
    }
    result=result/2;
    
    cout << result << endl;
    return 0;
}