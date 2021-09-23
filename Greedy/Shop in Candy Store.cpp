class Solution
{
public:
    vector<int> candyStore(int c[], int N, int K)
    {
        // Write Your Code here
        int n=2;
        vector<int>l(n,0);
        sort(c,c+N);
        if(K==N)
        { return l;
            
        }
        int t=N;
        int i=0;
        while(i<t)
        {
            l[0]=l[0]+c[i];
            i++;
             t-=K;
        }
        int p=N-1;
        int j=0;
        while(p>=j)
        {l[1]=l[1]+c[p];
          j=j+K;
          p--;
            
        }
        return l;
    }
};