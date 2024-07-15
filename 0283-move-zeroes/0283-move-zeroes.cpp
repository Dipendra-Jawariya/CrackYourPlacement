class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // in place
        int n = nums.size();
        int zero_ind = -1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero_ind = i;
                break;
            }
        }
        if(zero_ind == -1) return;
        
        for(int j = zero_ind + 1; j < n; j++) {
            if(nums[j] != 0) {
                swap(nums[j] , nums[zero_ind]);
                zero_ind++;
            }
        }
    }
};