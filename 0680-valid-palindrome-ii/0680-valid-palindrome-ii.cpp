class Solution {
private:
    bool isValidPalindrome(string s, int left, int right) {
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while(left <= right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
               return isValidPalindrome(s,left+1,right) || 
                    isValidPalindrome(s,left, right - 1);
            }
        }
        return true;
    }
};