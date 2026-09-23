class Solution {
public:
    int maxScore(vector<int>& cardScore, int k) {
        int n = cardScore.size();

        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardScore[i];
        }

        int ans = sum;

        int right = n - 1;

        for (int i = k - 1; i >= 0; i--) {
            sum -= cardScore[i];
            sum += cardScore[right];
            right--;

            ans = max(ans, sum);
        }

        return ans;
    }
};