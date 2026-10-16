
class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<long long> sum, sq, lazy;
    int n;

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        long long x = lazy[node];
        long long len = r - l + 1;

        sq[node] = (sq[node] + 2 * x * sum[node] % MOD
                    + x * x % MOD * len % MOD) % MOD;

        sum[node] = (sum[node] + x * len) % MOD;

        if (l != r) {
            lazy[node * 2] = (lazy[node * 2] + x) % MOD;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + x) % MOD;
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[node]++;
            push(node, l, r);
            return;
        }

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last[nums[i]] + 1;

            update(1, 0, n - 1, left, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};
