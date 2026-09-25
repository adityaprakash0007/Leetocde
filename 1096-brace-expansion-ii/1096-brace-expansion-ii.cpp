class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;

        while (i < s.size() && s[i] != '}') {
            set<string> term = parseTerm(s, i);

            result.insert(term.begin(), term.end());

            if (i < s.size() && s[i] == ',')
                i++;
        }

        return result;
    }

    set<string> parseTerm(string &s, int &i) {
        set<string> result = {""};

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> factor;

            if (s[i] == '{') {
                i++; 

                factor = parse(s, i);

                i++;
            } 
            else {
                factor.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (const string &a : result) {
                for (const string &b : factor) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};