class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        
        for(int i = 0; i < n; i++) {
                totalOnes += nums[i];
        }
        
        if(totalOnes == n) {
            return 0;
        }
        
        if(nums[0] == 1 && nums[n-1] == 1) {
            int i = 0;
            int ones = 0;
            while(nums[i] == 1) {
                ones++;
                i++;
            }
            i = n-1;
            while(nums[i] == 1) {
                ones++;
                i--;
            }
            if(ones == totalOnes) {
                return 0;
            }
        }
        
        int swap = 1e9;
        int currOnes = 0;
        
        for(int i = 0; i < totalOnes; i++) {
            currOnes += nums[i];
        }
        
        
        int startIndex = 0;
        
        for(int i = totalOnes; i < 2 * n; i++) {
            swap = min(swap,totalOnes - currOnes);
            if(nums[startIndex % n] == 1) {
                currOnes--;
            }
            startIndex++;
            if(nums[i % n] == 1) {
                currOnes++;
            }
        }
        return swap;
    }
};