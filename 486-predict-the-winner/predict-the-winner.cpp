class Solution {
public:
    pair<int, int> recurse(vector<int>& nums, int l, int r, vector<vector<pair<int, int>>>& dp) {
        if (l == r) return dp[l][r] = {nums[l], 0};

        pair<int, int> c1 = (dp[l + 1][r] != pair<int, int>{INT_MIN, INT_MIN}) 
                            ? dp[l + 1][r] 
                            : recurse(nums, l + 1, r, dp);
        
        pair<int, int> c2 = (dp[l][r - 1] != pair<int, int>{INT_MIN, INT_MIN}) 
                            ? dp[l][r - 1] 
                            : recurse(nums, l, r - 1, dp);

        int LeftScore = nums[l] + c1.second;
        int RightScore = nums[r] + c2.second;

        if (LeftScore >= RightScore) {
            return dp[l][r] = {LeftScore, c1.first};
        }
        
        return dp[l][r] = {RightScore, c2.first};
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MIN, INT_MIN}));
        
        pair<int, int> finalans = recurse(nums, 0, n - 1, dp);
        
        return finalans.first >= finalans.second;
    }
};