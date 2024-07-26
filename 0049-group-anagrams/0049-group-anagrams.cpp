class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string >> mpp;
        for(string str : strs) {
            string curr = str;
            sort(str.begin(),str.end());
            mpp[str].push_back(curr);
        }
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};