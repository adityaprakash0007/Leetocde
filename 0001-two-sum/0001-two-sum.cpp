class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>freq;
       for(int i=0;i<nums.size(); i++){
        int need = target - nums[i];
        if(freq.find(need) != freq.end()) return {freq[need], i};
        freq[nums[i]] = i;
       } 
       return {};
    }
};