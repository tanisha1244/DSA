class Solution {
public:
    int solve (int e,int f)
    {
        if(f==0||f==1)
        {
            return f;
        }
        if(e==1)
        {
            return f;
        }
        int minx=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int b=solve(e-1,k-1);
            int nb=solve(e,f-k);
            int temp=1+max(b,nb);
            minx=min(minx,temp);
        }
        return minx;
    }
    int superEggDrop(int k, int n) {
        if(k==0){return 0;}
        return solve(k,n);
        
    }
};
 //Time: O(n*(2^min(n,k))), Space: O(n)
