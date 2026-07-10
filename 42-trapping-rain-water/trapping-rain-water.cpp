class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() == 0 || height.size() == 1){
            return 0;
        }
        
        int left = 0;
        int right = height.size() - 1;
        int leftMax = left;
        int rightMax = right;
        int total = 0;

        while(left < right){
            if(height[left] < height[right]){
                left++;
                if(height[left] < height[leftMax]){
                    total += height[leftMax] - height[left];
                }else{
                    leftMax = left;
                }
                
            }else{
                right--;
                if(height[right] < height[rightMax]){
                    total += height[rightMax] - height[right];
                }else{
                    rightMax = right;
                }
            }
        }

        return total;
    }
};