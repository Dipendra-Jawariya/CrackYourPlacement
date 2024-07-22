class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1;
        int j = 0;
        while(i >= 0  && j < n) {
            if(nums1[i] > nums2[j]) {
                swap(nums1[i],nums2[j]);
                i--;j++;    
            }
            else break;
        }
       
        j = 0;
        for(int i = m; i < m+n; i++) {
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
    }
};