class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int curmax = INT_MIN;
        auto sortpair = [](pair<int, int> &p1, pair<int, int> &p2) { return p1.first > p2.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(sortpair)> pqpair(sortpair);
        vector<int> idx(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i].size() == idx[i]) continue;
            pqpair.push({nums[i][0],i});
            idx[i] = 1;
            curmax = max(curmax, nums[i][0]);
        }
        int resstart = pqpair.top().first;
        int resend = curmax;
        while(idx[pqpair.top().second] < nums[pqpair.top().second].size()) {
            int tmp = pqpair.top().second;
            pqpair.pop();
            pqpair.push({nums[tmp][idx[tmp]], tmp});
            curmax = max(curmax, nums[tmp][idx[tmp]]);
            idx[tmp]++;
            if(resend - resstart > curmax - pqpair.top().first) {
                resstart = pqpair.top().first;
                resend = curmax;
            }
        }
        return {resstart, resend};
    }
};
