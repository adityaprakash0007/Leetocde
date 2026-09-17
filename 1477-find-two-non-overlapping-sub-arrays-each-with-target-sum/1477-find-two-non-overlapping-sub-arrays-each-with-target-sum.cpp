

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> left(n, INF);

        int sum = 0, start = 0, best = INF;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target && start <= i) {
                sum -= arr[start++];
            }
            if (sum == target) {
                best = min(best, i - start + 1);
            }
            left[i] = best;
        }

        vector<int> right(n, INF);

        sum = 0;
        int end = n - 1;
        best = INF;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            while (sum > target && end >= i) {
                sum -= arr[end--];
            }
            if (sum == target) {
                best = min(best, end - i + 1);
            }
            right[i] = best;
        }

        int ans = INF;
        for (int i = 0; i < n - 1; i++) {
            if (left[i] != INF && right[i + 1] != INF) {
                ans = min(ans, left[i] + right[i + 1]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};