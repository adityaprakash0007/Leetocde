
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n == 0) return 0;

        vector<pair<int, int>> meeting;

        for(int i = 0; i < n; i++) {
            meeting.push_back({intervals[i][1], intervals[i][0]});
        }

        sort(meeting.begin(), meeting.end());

        int count = 0;
        int lastEnd = meeting[0].first;

        for(int i = 1; i < n; i++) {
            if(meeting[i].second < lastEnd) {
                count++;
            }
            else {
                lastEnd = meeting[i].first;
            }
        }

        return count;
    }
};