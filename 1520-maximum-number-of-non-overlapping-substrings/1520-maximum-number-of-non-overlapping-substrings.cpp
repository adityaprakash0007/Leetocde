class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';

            if (i != first[c])
                continue;

            int end = last[c];
            bool valid = true;

            for (int j = i; j <= end; ++j) {
                int x = s[j] - 'a';

                if (first[x] < i) {
                    valid = false;
                    break;
                }

                end = max(end, last[x]);
            }

            if (valid)
                intervals.push_back({i, end});
        }

        vector<string> ans;
        int prevEnd = -1;

        for (auto [start, end] : intervals) {
            if (start > prevEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            } else if (end < prevEnd) {
                ans.back() = s.substr(start, end - start + 1);
                prevEnd = end;
            }
        }

        return ans;
    }
};