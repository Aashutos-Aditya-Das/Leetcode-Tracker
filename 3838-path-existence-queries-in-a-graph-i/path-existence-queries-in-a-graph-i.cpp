class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<int> comp(n);
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff)
                comp[i] = comp[i - 1];
            else
                comp[i] = comp[i - 1] + 1;
        }

        vector<bool> result;

        for (auto &x : queries) {
            result.push_back(comp[x[0]] == comp[x[1]]);
        }

        return result;
    }
};