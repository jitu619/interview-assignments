class Solution {
public:
    //RDLU
    int y[4]={1,0,-1,0};
    int x[4]={0,-1,0,1};
    bool visited[7][7];
    
    bool isPossible(int m,int n,int x,int y){
        if(x>=m || x<0 || y>=n || y<0 || visited[x][y])
            return false;
        return true;
    }
    
    bool traverse(vector<vector<char>>& board,string &word,int row,int col,int idx){
        if(idx==word.length()){
            return true;
        }
        if(isPossible(board.size(),board[0].size(),row,col) && word[idx]==board[row][col]){
            for(int i=0;i<4;i++){
                visited[row][col]=true;
                if(traverse(board,word,row+x[i],col+y[i],idx+1))
                    return true;
                visited[row][col]=false;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        memset(visited,false,sizeof(visited));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(traverse(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
