class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        
        map<char,int> mpp;
        for(char ch : t) {
            mpp[ch]++;
        }
        
        int left = 0;
        int right = 0;
        int cnt = 0;
        int minLen = 1e9;
        int sIndex = -1;
        
        while(right < n) {
            if(mpp[s[right]] > 0) {
                cnt++;
            }
            mpp[s[right]]--;
            
            while(cnt == t.size()) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    sIndex = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex,minLen);
    }
};