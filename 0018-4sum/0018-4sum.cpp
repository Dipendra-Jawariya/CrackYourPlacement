class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                
                set<long long> hashSet;
                for(int k = j + 1; k < n; k++) {
                    
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long rem = target - sum;
                    if(hashSet.find(rem) != hashSet.end()) {
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)(rem)};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};