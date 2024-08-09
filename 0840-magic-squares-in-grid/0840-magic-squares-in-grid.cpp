class Solution {
private:
    bool magicSquare(int r,int c,vector<vector<int>> &grid) {
        vector<int> arr(10,0);
        // check if grid has only 1 to 9 and no number is duplicate
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || arr[num] > 0) {
                    return false;
                }
                arr[num]++;
            }
        }
        // get row Sum
        int rSum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        // every row has same sum
        for(int i = 0; i < 3; i++) {
            int currSum = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
            if(currSum != rSum) {
                return false;
            }
        }
        int cSum = grid[r][c] + grid[r+1][c] + grid[r+2][c];
        
        
        if(rSum != cSum) {
            return false;
        }
        
        // every col has same sum
        for(int i = 0; i < 3; i++) {
            int currSum =  grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i];
            if(currSum != cSum) {
                return false;
            }
        }
        
        // diagonal Sum
        int diaSum = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        if(diaSum != rSum) return false;
        // antidiagonal Sum
        int antidiaSum = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        if(antidiaSum != diaSum) return false;
        
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row < 3 || col < 3) {
            return 0;
        }
        
        int cnt = 0;
        // generate all matrix of size 3 X 3
        for(int i = 0; i <= row - 3; i++) {
            for(int j = 0; j <= col - 3; j++) {
                int rowNum = i;
                int colNum = j;
                if(magicSquare(rowNum,colNum,grid)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};