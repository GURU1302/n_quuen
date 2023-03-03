#include <bits/stdc++.h> 

void addSolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}


bool isSafe(vector<vector<int>> &board,int row,int col,int n){
    int x=row;
    int y=col;

    while(y>=0){
        if(board[x][y]==1)
        return false;
        y--;
    }

     x=row;
    y=col;

    while(x>=0 && y>=0){
        if(board[x][y]==1)
        return false;
        y--;
        x--;
    }

   x=row;
   y=col;

    while(x<n && y>=0){
        if(board[x][y]==1)
        return false;
        y--;
        x++;
    }
    return true;
}


void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n){

//base case
if(col==n){
    addSolution(ans,board,n);
    return;
}

//handle one condition and rest will be handled by resursion

for(int row=0;row<n;row++){
    if(isSafe(board,row,col,n)){
        board[row][col]=1;
        solve(col+1,ans,board,n);
        //backtrack
        board[row][col]=0;
    }

}
