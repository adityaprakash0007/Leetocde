class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> prefix(n, vector<long long>(k + 1, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            prefix[i][0] = (i > 0 ? prefix[i-1][0] : 0) + 1;
        }
        
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    dp[i][j] = dp[i-1][j];
                    dp[i][j] = (dp[i][j] + prefix[i-1][j-1]) % MOD;
                }
                
                prefix[i][j] = ((i > 0 ? prefix[i-1][j] : 0) + dp[i][j]) % MOD;
            }
        }
        
        return dp[n-1][k];
    }
};