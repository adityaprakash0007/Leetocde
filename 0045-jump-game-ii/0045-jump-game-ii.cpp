
class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int end = 0;
        int maxIdx = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            maxIdx = max(maxIdx, i + nums[i]);

            if(i == end) {
                jumps++;
                end = maxIdx;
            }
        }

        return jumps;
    }
};
