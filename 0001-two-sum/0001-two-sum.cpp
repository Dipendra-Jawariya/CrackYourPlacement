class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp; // o(nlogn)
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }
        
        for(int i = 0; i < n; i++) {
            int rem = target - nums[i]; 
            if(mpp.find(rem) != mpp.end() && i != mpp[rem]) {
                return {i,mpp[rem]};
            }
        }
        return ans;
    }
};