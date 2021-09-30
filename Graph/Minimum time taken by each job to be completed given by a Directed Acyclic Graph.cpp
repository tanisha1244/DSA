#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
vector<int> graph[maxN];
int indegree[maxN];

int job[maxN];

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    indegree[v]++;
}

void printOrder(int n, int m)
{
  
    queue<int> q;
 
 
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            job[i] = 1;
        }
    }
 
    
    while (!q.empty()) {
 
        
        int cur = q.front();
 
       
        q.pop();
 
        for (int adj : graph[cur]) {
 
            
            indegree[adj]--;
            if (indegree[adj] == 0) {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }
 
    for (int i = 1; i <= n; i++)
        cout << job[i] << " ";
    cout << "\n";
}
 
int main()
{
    // Given Nodes N and edges M
    int n, m;
    n = 10;
    m = 13;
 
    // Given Directed Edges of graph
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
 
    // Function Call
    printOrder(n, m);
    return 0;
}