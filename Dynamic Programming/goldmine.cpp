class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> arr)
    {
        // code here
       int DP[n][m];

    memset(DP, 0, sizeof(DP));

    for (int i = 0; i < n; i++)
        DP[i][0] = arr[i][0];

    //for every column
    for (int j = 1; j < m; j++) {
        //check which option is better accordingly
        for (int i = 0; i < n; i++) {
            //choosing max of possible moves
            DP[i][j] = arr[i][j];
            int val = DP[i][j - 1];
            if (i - 1 >= 0) {
                if (val < DP[i - 1][j - 1])
                    val = DP[i - 1][j - 1];
            }
            if (i + 1 < n) {
                if (val < DP[i + 1][j - 1])
                    val = DP[i + 1][j - 1];
            }
            DP[i][j] += val;
        }
    }
    // find the maximum of the last column
    int gold = DP[0][m - 1];
    for (int i = 1; i < n; i++) {
        if (DP[i][m - 1] > gold)
            gold = DP[i][m - 1];
    }

    return gold;
        
    }
};