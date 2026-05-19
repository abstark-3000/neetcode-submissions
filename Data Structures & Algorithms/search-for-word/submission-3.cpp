class Solution {
public:
    void f(int i,int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,string &word,bool &poss)
    {
        // if(vis[i][j]==1)return;
        vis[row][col]=1;
        if(i==word.size()-1)
        {
            if(board[row][col]==word[i])
            {
                poss=true;
                return;
            }
            // else return;
        }
        if(poss)return;
        if(row-1>=0 && board[row-1][col]==word[i+1] && vis[row-1][col]==0)f(i+1,row-1,col,board,vis,word,poss);
        // if(poss)return;
        // vis[row][col]=0;
        if(row+1<board.size() && board[row+1][col]==word[i+1] && vis[row+1][col]==0)f(i+1,row+1,col,board,vis,word,poss);
        // if(poss)return;
        // vis[row][col]=0;
        if(col-1>=0 && board[row][col-1]==word[i+1] && vis[row][col-1]==0)f(i+1,row,col-1,board,vis,word,poss);
        // if(poss)return;
        // vis[row][col]=0;
        if(col+1<board[0].size() && board[row][col+1]==word[i+1] && vis[row][col+1]==0)f(i+1,row,col+1,board,vis,word,poss);
        if(poss)return;
        vis[row][col]=0;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>>vis(m,vector<int>(n,0));
                    bool poss=false;
                    f(0,i,j,board,vis,word,poss);
                    if(poss)return true;
                }

            }
        }
        return false;   
    }
};
