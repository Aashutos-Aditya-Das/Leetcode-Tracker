static inline int pref[2001];
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();
        fill(pref , pref + 2 * n + 1 , 0);
        pref[n] = 1;
        int curr = n;
        long long res = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == target){
                sum += pref[curr];
                ++curr;
                ++pref[curr];
            }
            else{
                --curr;
                sum -= pref[curr]++;
            }
            res += sum;
        }
        return res;
    }
};