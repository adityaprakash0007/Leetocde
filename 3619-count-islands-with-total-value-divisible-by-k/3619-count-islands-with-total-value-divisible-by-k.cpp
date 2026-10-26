class Solution {
public:
    int rows, cols;

    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols ||
            grid[i][j] == 0) {
            return 0;
        }

        long long sum = grid[i][j];

        grid[i][j] = 0; 

        sum += dfs(grid, i + 1, j);
        sum += dfs(grid, i - 1, j);
        sum += dfs(grid, i, j + 1);
        sum += dfs(grid, i, j - 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
