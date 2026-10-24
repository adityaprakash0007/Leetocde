
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int left = 0;
        int count = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;

                if (mp[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
