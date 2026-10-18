class Solution {
public:
    long long MOD = 1e9 + 7;
    long long dp[1001][1001];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        long long ways = dp[n - 1][left.size()];

        return ways * leftWays % MOD * rightWays % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            dp[i][0] = dp[i][i] = 1;

            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] +
                            dp[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};