class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        set<vector<int>> outSet;
        int n = nums.size();
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1;j<n-2;j++){
                long long NewTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int l = j+1; 
                int r = n-1;
                while(l < r){
                    if(nums[l] + nums[r] < NewTarget){
                        l++;
                    }else if(nums[l] + nums[r] > NewTarget){
                        r--;
                    }else{
                        outSet.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        for(auto it : outSet){
            result.push_back(it);
        }

        return result;
        
    }
};