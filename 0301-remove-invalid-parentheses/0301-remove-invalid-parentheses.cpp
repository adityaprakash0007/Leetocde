class Solution {
public:
    bool isValid(string s) {
        int balance = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                balance++;
            }
            else if (s[i] == ')') {
                balance--;
            }

            if (balance < 0) {
                return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        unordered_set<string> level;
        level.insert(s);

        while (true) {
            for (auto str : level) {
                if (isValid(str)) {
                    ans.push_back(str);
                }
            }

            if (ans.size() > 0) {
                return ans;
            }

            unordered_set<string> nextLevel;

            for (auto str : level) {
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] != '(' && str[i] != ')') {
                        continue;
                    }

                    string newString = str.substr(0, i) + str.substr(i + 1);

                    nextLevel.insert(newString);
                }
            }

            level = nextLevel;
        }
    }
};