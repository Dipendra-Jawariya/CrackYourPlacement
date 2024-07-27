class Solution {
private:
    string handler(int start,int end,vector<string>&words, int betweenSpace,int extraSpace,
                   int maxWidth)  {
        string ans = "";
        for(int i = start; i < end; i++) {
            ans += words[i];
            
            if(i == end - 1) { // last word of my line - no space after last words of a line
                // we would have already added the space in all other words apart from last word.
                continue;
            }
            for(int j = 1; j <= betweenSpace; j++) {
                ans += " ";
            }
            if(extraSpace-- > 0) {
                ans += " ";
            }
        }
        while(ans.length() < maxWidth) {
            ans += " ";
        }
        return ans;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        
        while(i < n) {
            int letterCount = words[i].size(); // Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
            int spaceSlot = 0;
            int j = i + 1;
            while(j < n && (letterCount + words[j].size() + 1 + spaceSlot) <= maxWidth) {
                letterCount += words[j].size();
                spaceSlot++;
                j++;
            }
            int remainingSlot = maxWidth - letterCount;
            
            int betweenSpace = (spaceSlot == 0)? 0 : remainingSlot / spaceSlot;
            int extraSpace = (spaceSlot == 0)? 0 : remainingSlot % spaceSlot;
            
            if(j == n) { // last line h toh left justified rakho
                betweenSpace = 1;
                extraSpace = 0; // even space na daalni ho toh jese ek jgaah 3 fr ek jagah 2
            }
            // function which will return a string and hadles betweenSpaces
            string curr = handler(i,j,words,betweenSpace,extraSpace,maxWidth);
            ans.push_back(curr);
            i = j;
        }
        return ans;
    }
};