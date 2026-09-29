class Solution {
public:
    int m, n;
    int dp[105][105][205];

    bool solve(int i, int j, int bal, vector<vector<char>>& grid) {
        bal += (grid[i][j] == '(' ? 1 : -1);

        if (bal < 0) return false;
        if (bal > (m - 1 - i) + (n - 1 - j)) return false;

        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool ans = false;

        if (i + 1 < m)
            ans |= solve(i + 1, j, bal, grid);

        if (j + 1 < n)
            ans |= solve(i, j + 1, bal, grid);

        return dp[i][j][bal] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2)
            return false;

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid);
    }
};