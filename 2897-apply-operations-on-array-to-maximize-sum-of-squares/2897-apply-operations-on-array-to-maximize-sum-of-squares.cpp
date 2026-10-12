class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int bits[30] = {0};

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 30; j++) {
                if (nums[i] & (1 << j)) {
                    bits[j]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int j = 29; j >= 0; j--) {
                if (bits[j] > 0) {
                    num |= (1LL << j);
                    bits[j]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};
