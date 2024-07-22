class Solution {
private:
    bool find(int i,int j,int ind,string word,vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();
        if(ind == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$') {
            return false;
        }
        if(board[i][j] != word[ind]) {
            return false;
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        char temp =  board[i][j];
        board[i][j] = '$'; // visited
        for(int index = 0; index < 4; index++) {
            int newi = i + delRow[index];
            int newj = j + delCol[index];
            
            if(find(newi,newj,ind+1,word,board)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0] && find(i,j,0,word,board)) {
                    return true;
                }
            }
        }
        return false;
    }
};