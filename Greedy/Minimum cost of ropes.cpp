class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code her
        if(n<2)
        {
            return 0;
        }
        priority_queue<long long,vector<long long>,greater<long long>>q;
        for(long long i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        long long s=0;
        while(!q.empty())
        {  if(q.size()<2)
        {
            s=0;
            break;
        }
            long long x=q.top();
            q.pop();
           long long y=q.top();
            q.pop();
             x=x+y;
             if(!q.empty()){
                q.push(x);

            }
            s=s+x;
        }
        return s;
    }
};

