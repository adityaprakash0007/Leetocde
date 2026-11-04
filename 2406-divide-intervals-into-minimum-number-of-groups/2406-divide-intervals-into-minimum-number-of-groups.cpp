class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> Arrival, Departure;

        for(int i = 0; i < intervals.size(); i++) {
            Arrival.push_back(intervals[i][0]);
            Departure.push_back(intervals[i][1]);
        }

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int ans = 0;
        int a = 0, d = 0;
        int platform = 0;

        while(a < Arrival.size()) {
            if(Arrival[a] <= Departure[d]) {
                platform++;
                a++;
            }
            else {
                platform--;
                d++;
            }

            ans = max(ans, platform);
        }

        return ans;
    }
};