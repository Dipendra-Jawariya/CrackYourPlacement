class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false, eseen = false, dotseen = false;
        int countMinusPlus = 0;
        
        for(int i = 0; i < s.size(); i++) {
            
            // digit
            if(isdigit(s[i])) {
                digitSeen = true;
            }
            // minus/ plus
            else if(s[i] == '-' || s[i] == '+') {
                if(countMinusPlus == 2) {
                    return false;
                }
                if(i > 0 && s[i-1] != 'e' && s[i-1] != 'E')  {
                    return false;
                }
                if(i == s.size() - 1) {
                    return false;
                }
                countMinusPlus++;
            }
            // dot
            else if(s[i] == '.') {
                if(eseen || dotseen) {
                    return false;
                }
                if(i == s.size() - 1 && !digitSeen)  {
                    return false;
                }
                dotseen = true;
            }
            // E/e
            else if(s[i] == 'e' || s[i] == 'E') {
                if(eseen || !digitSeen || i == s.size() - 1) {
                    return false;
                }
                eseen = true;
            }
            else {
                return false;
            }
        }
        return true;
    }
};