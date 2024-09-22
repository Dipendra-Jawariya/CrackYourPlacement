class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st;
        for(string str : bannedWords) {
            st.insert(str);
        }
        int cnt = 0;
        for(string msg : message) {
            if(st.find(msg) != st.end()) {
                cnt++;
            }
        }
        return cnt >= 2 ? true : false;
    }
};