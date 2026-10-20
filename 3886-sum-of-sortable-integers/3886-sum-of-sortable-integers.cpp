
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, 1000000000);
        vector<int> prefDrop(n, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n / k; k++) {
            if (n % k != 0) {
                continue;
            }

            for (int j = 0; j < 2; j++) {
                if (j == 1 && k == n / k) {
                    continue;
                }

                int x = (j == 0 ? k : n / k);
                bool ok = true;

                for (int start = 0; start < n; start += x) {
                    int end = start + x - 1;

                    int drops = prefDrop[end] - prefDrop[start];

                    if (nums[end] > nums[start]) {
                        drops++;
                    }

                    if (drops > 1 || prefMax[start] > suffMin[start]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    ans += x;
                }
            }
        }

        return ans;
    }
};
