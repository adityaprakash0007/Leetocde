class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        vector<long long> cost;

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                leftSum += val;
            }
            else {
                right.insert(val);
                rightSum += val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                leftSum -= v;

                right.insert(v);
                rightSum += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                rightSum -= v;

                left.insert(v);
                leftSum += v;
            }
        };

        auto remove = [&](int val) {
            if (left.find(val) != left.end()) {
                left.erase(left.find(val));
                leftSum -= val;
            }
            else {
                right.erase(right.find(val));
                rightSum -= val;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                leftSum -= v;

                right.insert(v);
                rightSum += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                rightSum -= v;

                left.insert(v);
                leftSum += v;
            }
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long operations =
                    median * left.size() - leftSum +
                    rightSum - median * right.size();

                cost.push_back(operations);
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];

                if (i + x <= n) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i] + dp[i + x][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};