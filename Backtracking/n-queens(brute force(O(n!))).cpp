class Solution {
   bool issafe(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
    void solve(int col,vector<string>&bord,int n,vector<vector<string>>&ans)
    {
        if(col==n)
        {  
            ans.push_back(bord);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(i,col,bord,n))
            {
                bord[i][col]='Q';
                solve(col+1,bord,n,ans);
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
        solve(0,bord,n,ans);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};