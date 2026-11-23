class Solution {
public:
    vector<vector<string>> result;
    int N;
    bool isValid(vector<string>& board, int row, int col){
// agar koi bhi Q bilkul upar hoo
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }
// agar koi bhi q left diagnonally ho
        for(int i = row - 1, j = col - 1; i>=0 && j>=0; i--, j--){
                if(board[i][j] == 'Q') return false;
        }
/// agar koi bhi q right diagonally hoo
        for(int i = row - 1,  j = col + 1; i>=0 && j<N; i--, j++){
                if(board[i][j] == 'Q') return false;
        }
    return true;
    }
    void solve(vector<string>& board, int row){
        if(row >= N){
            //iska mtlb hmne ek column ki sari rows ko traverse kr liye h
            result.push_back(board);
            return;
        }

        for(int col = 0; col < N; col++){
            if(isValid(board, row, col)){ // check krega ki agar wo index pehle valid h tabhi hum proceed krenge, warna nhi
                board[row][col] = 'Q'; // and agar hua toh 'Q' insert krdenge
                solve(board, row+1); // and age rows check krenge
                board[row][col] = '.'; // usse pehle 'Q' wale ko '.' krdenge
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //pehle ek vector<string> bna lo
        N=n;
        result.clear();
        vector<string> board(n, string(n, '.'));

        solve(board, 0); // 0th row se shuru krenge
        return result;
    }
};