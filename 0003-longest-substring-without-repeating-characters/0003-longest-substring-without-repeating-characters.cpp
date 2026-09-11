class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLen = 0;
        int left = 0;
        for(int i=0; i<s.size(); i++){
            while(st.count(s[i])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            maxLen = max(maxLen, i-left+1);
        }
        return maxLen;
    }
};