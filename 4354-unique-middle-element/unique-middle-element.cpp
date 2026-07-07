class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int element = nums[(nums.size() - 1)/2];
        int count = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == element){
                count++;
                if(count > 1){
                    return false;
                }else{
                    continue;
                }
            }
        }
        return true;

    }
};