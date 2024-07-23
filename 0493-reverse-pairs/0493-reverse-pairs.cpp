class Solution {
    int cnt = 0;
private:
    void merge(vector<int> &nums,int low,int mid,int high) {
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(nums[left++]);
        }
        while(right <= high) {
            temp.push_back(nums[right++]);
        }
        for(int i = low; i <= high; i++) {
            nums[i] = temp[i-low];
        }
    }
    void countPair(vector<int> &nums,int low,int mid,int high) {
        int right = mid + 1;
        for(int i = low; i <= mid; i++) {
            while(right <= high && (long long)nums[i] > (long long)2 * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
    }
     void mergeSort(vector<int> &nums,int low,int high) {
         if(low >= high) return;
         
         int mid = (low + high) / 2;
         mergeSort(nums,low,mid); // left half
         mergeSort(nums,mid+1,high); // right half
         countPair(nums,low,mid,high); // this function finds the number of the pairs
         merge(nums,low,mid,high); // merging sorted halves
     }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return cnt;
    }
};