class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++){
           int reverseVal = (26-(s[i]-'a'));
            sum += (i+1)*reverseVal;
        }
        return sum;
    }
};