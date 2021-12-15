class Solution {
public:
    bool traverse(vector<vector<char>>& board,int l,int r){
        unordered_map<char,int> mp;
        for(int i=0;i<9;i++){
           if(board[l][i]!='.'){
                if(mp.find(board[l][i])!=mp.end()){
                    // cout<<"1: "<<board[l][i]<<" ";
                    return false;
                }
                mp[board[l][i]]++;
            }
       }
        // cout<<"map size: "<<mp.size()<<"\n";
        mp.clear();
        // cout<<"map size: "<<mp.size()<<"\n";
        for(int i=0;i<9;i++){
            if(board[i][r]!='.'){
                if(mp.find(board[i][r])!=mp.end()){
                    // cout<<"2: "<<board[i][r]<<" ";
                    return false;
                }
                mp[board[i][r]]++;
            }
        } 
        // cout<<"map size: "<<mp.size()<<"\n";
        mp.clear();
        // cout<<"map size: "<<mp.size()<<"\n";
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[l/3*3+i][r/3*3+j]!='.'){
                    if(mp.find(board[l/3*3+i][r/3*3+j])!=mp.end()){
                        // cout<<"3: "<<board[l+i][r+j]<<" ";
                        return false;
                    }
                    mp[board[l/3*3+i][r/3*3+j]]++;
                }
            }
        } 
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
               if(traverse(board,i,j)==false){
                   // cout<<"\n"<<i/3*3<<" "<<j/3*3<<"\n";
                   return false;
               }
            }
        }
        return true;  
    }
};
