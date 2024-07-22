class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int,string> height_to_name_map;
        for(int i = 0; i < names.size(); i++) {
            height_to_name_map[heights[i]] = names[i];
        }
        
        sort(heights.begin(),heights.end());
        
        vector<string> sorted_names(n);
        
        for(int i = n - 1; i >= 0; i--) {
            sorted_names[n-i-1] = height_to_name_map[heights[i]];
        }
        return sorted_names;
    }
};