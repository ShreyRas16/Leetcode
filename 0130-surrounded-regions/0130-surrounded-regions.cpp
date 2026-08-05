class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=true;
            }
            if(board[i][board[0].size()-1]=='O'){
                q.push({i,board[0].size()-1});
                visited[i][board[0].size()-1]=true;
            }
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                visited[0][j]=true;
            }
            if(board[board.size()-1][j]=='O'){
                q.push({board.size()-1,j});
                visited[board.size()-1][j]=true;
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
           pair<int,int> temp=q.front();
           q.pop();
              for(int k=0;k<4;k++){
                int nr=temp.first+dr[k];
                int nc=temp.second+dc[k];
                if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]=='O' && !visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                }
              }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }
    }
};