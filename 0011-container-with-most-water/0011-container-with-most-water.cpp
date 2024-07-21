class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        
        int ans = INT_MIN;
        while(low <= high) {
            int width = high - low;
            int minHeight = min(height[high] , height[low]);
            
            ans = max(ans , width * minHeight);
            
            if(minHeight == height[low]) {
                low++;
            } else {
                high--;
            }
        }
        return ans;
    }
};