class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total_elements = size1 + size2;
        int left_side_size = (size1 + size2 + 1) / 2; 
        int low_index = 0;
        int high_index = size1;
        
        while (low_index <= high_index) {
            int midpoint1 = (low_index + high_index) / 2; 
            int midpoint2 = left_side_size - midpoint1; 
            
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            
            if (midpoint1 < size1) {
                r1 = nums1[midpoint1];
            }
            if (midpoint2 < size2) {
                r2 = nums2[midpoint2];
            }
            if (midpoint1 - 1 >= 0) {
                l1 = nums1[midpoint1 - 1];
            }
            if (midpoint2 - 1 >= 0) {
                l2 = nums2[midpoint2 - 1];
            }
            
            if (l1 <= r2 && l2 <= r1) {
                if (total_elements % 2 == 1) {
                    double ans1 = max(l1, l2);
                    return ans1;
                }
                else {
                    int median1 = max(l1, l2);
                    int median2 = min(r1, r2);
                    double sum_val = median1 + median2;
                    double final_ans = sum_val / 2.0;
                    return final_ans;
                }
            }
            else if (l1 > r2) {
                high_index = midpoint1 - 1;
            }
            else {
                low_index = midpoint1 + 1;
            }
        }
        
        return 0.0; 
    }
};
