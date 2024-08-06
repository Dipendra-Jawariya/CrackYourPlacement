class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        // 2,3,4,5,6,7,8,9
        unordered_map<int,int> mpp; // int arr[10] ---> 0 --- 9
        int result = 0;
        
        int assign_key = 2;
        for(char &ch : word) {
            if(assign_key > 9) {
                assign_key = 2;
            }
            mpp[assign_key]++;
            result += mpp[assign_key];
            
            assign_key++;
        }
        return result;
    }
};