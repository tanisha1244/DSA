#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int arr[], int M, int V) 
	{ 
	    // Your code goes here
	    int max=V+1;
	    vector<int> d(V+ 1,max );
	    d[0]=0;
	    for(int i=1;i<=V;i++)
	    {
	        for(int j=0;j<M;j++)
	        { if (arr[j] <= i) {
	            d[i]=min(d[i],d[i-arr[j]]+1);}
	                 }
	        
	    }
	     if(d[V]>V){return -1;}
	     else{
	         return d[V];
	     }
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends