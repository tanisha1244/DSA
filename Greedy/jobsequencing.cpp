#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{ 

    public:
    //Function to find the maximum profit and the number of jobs don
vector<int> JobScheduling(Job arr[], int n) 
{ 
    
  vector<pair<int,int>>a;
  for(int i=0;i<n;i++)
  {
      a.push_back(make_pair(arr[i].profit,arr[i].dead));
      
  }
  sort(a.rbegin(),a.rend());//O(nlogn) sorting acc to profit
 int maxi=INT_MIN;
  for(int i=0;i<n;i++)
  {
      maxi=max(maxi,arr[i].dead);
  }
  vector<int>dp(maxi,-1);
  int sum=0;
  int l=0;
  for(int i=0;i<n;i++)
  {  int j=a[i].second-1;
     while(j>=0&&dp[j]!=-1)
     {
             j--;
     }
      if(dp[j]==-1)
      { l++;
          dp[j]=a[i].first;
          sum=sum+dp[j];
      }
  }
  vector<int>f(2);
  f[0]=l;
  f[1]=sum;
  return  f;
  
}
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends