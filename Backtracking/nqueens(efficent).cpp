class Solution {
    
  
    void solve(int col,vector<string>&bord,int n,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upperdig,vector<int>&lowerdig)
    {
        if(col==n)
        {  
            ans.push_back(bord);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(leftrow[i]==0&&upperdig[n-1-i+col]==0&&lowerdig[i+col]==0)
            {
                bord[i][col]='Q';
                leftrow[i]=1;
                    upperdig[n-1+col-i]=1;
                    lowerdig[i+col]=1;
                solve(col+1,bord,n,ans,leftrow,upperdig,lowerdig);
                leftrow[i]=0;
                upperdig[n-1-i+col]=0;
                lowerdig[i+col]=0;
                bord[i][col]='.';
            }
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>bord(n);
        string s(n,'.');
        for (int i=0;i<n;i++)
        {
            bord[i]=s;
        }
        vector<int>leftrow(n,0),upperdig(2*n-1,0),lowerdig(2*n-1,0);
        solve(0,bord,n,ans,leftrow,upperdig,lowerdig);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};