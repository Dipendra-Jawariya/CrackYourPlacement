class Solution {
private:
    void f(int open,int close,int n,string str, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(str);
            return;
        }
        if(open + 1 <= n) {
            str += "(";
            f(open+1,close,n,str,ans);
            str.pop_back();
        }
        if(close + 1 <= open && close + 1 <= n) {
            str += ")";
            f(open,close + 1,n,str,ans);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        f(0,0,n,str,ans);
        return ans;
    }
};