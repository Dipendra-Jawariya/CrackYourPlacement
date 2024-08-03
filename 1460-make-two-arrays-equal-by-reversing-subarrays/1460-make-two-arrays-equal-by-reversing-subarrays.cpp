class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mpp;
        for(int tar : target) {
            mpp[tar]++;
        }
        
        map<int,int> mpp1;
        for(int curr : arr) {
            mpp1[curr]++;
        }
        
        return mpp1 == mpp;
    }
};