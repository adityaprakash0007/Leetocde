class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        for (int right = 0; right < s.size(); right++) { 
          mp[s[right]]++;
          maxFreq = max(maxFreq, mp[s[right]]);
          while((right-left+1)-maxFreq > k){
            mp[s[left]]--;
            left++;
          }
          maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};