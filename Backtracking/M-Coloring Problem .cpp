#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool ispossible(int cur,vector<int>&color,bool graph[101][101],int co,int n)
{
    for(int k=0;k<n;k++)
    {
        if(k!=cur&&graph[k][cur]==1&&color[k]==co)//checking if the adj node have the same color or not if 
                                                  //yes then return false
        {
            return false;
        }
    }
    return true;
}
bool coloringgraphpossible(int cur,vector<int>&color,bool graph[101][101],int m,int n)
{
    if(cur==n)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(ispossible(cur,color,graph,i,n)) //if we can color the node by color i 
                                             //means no adj node of this color
        {
            color[cur]=i;
            if(coloringgraphpossible(cur+1,color,graph,m,n))return true;//checking for leftout nodes
            color[cur]=0;//if rest of the node are not able to color with this color then we have to 
                         // remove this color and check for rest of the color
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>color(V);
    if(coloringgraphpossible(0,color,graph,m,V))return true;
    return false;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends