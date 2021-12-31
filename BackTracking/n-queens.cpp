class Solution {
public:
    vector<vector<string>> ans;
    bool isPossible(vector<string> &board,int row,int col){
        // Checking column
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        // Checking left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        // Checking right diagonal
        for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    
    
    void traverse(vector<string> &board,int row){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(isPossible(board,row,i)){
                board[row][i]='Q';
                traverse(board,row+1);
                board[row][i]='.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        traverse(board,0);
        return ans;
    }
};
