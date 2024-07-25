class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        for(int i = 0; i < n; i++) {
            if(haystack[i] == needle[0]) {
                int size = needle.size();
                string str = haystack.substr(i,size);
                cout<<str<<" "<<endl;
                if(needle == str) {
                    return i;
                }
            }
        }
        return -1;
    }
};