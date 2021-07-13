#include<bits/stdc++.h>
using namespace std;
//colum = x,     row = y

bool check_square(vector<vector<int> >& board, int row, int colum);

bool solve_sudoku(vector<vector<int> >& board, int row, int colum);

int main(){
    vector<vector<int> > board;
    for(int i = 0; i < 9; i++){
        vector<int> row(9, -1);
        board.push_back(row);
    }
    

    int x, y, value;
    // fill coordinates with value
    // if you do not want to fill anymore then input -1, -1, -1;
    cin >> x >> y >> value;
    cout << endl;
    while(x != -1 && y != -1 && value != -1){
        board[x][y] = value;
        cin >> x >> y >> value;
        cout << endl;
    }
 

    solve_sudoku(board, 0, 0);
    if(!solve_sudoku(board, 0, 0))cout << "unsolvable";
    else{
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

}

bool check_square(vector<vector<int> >& board, int row, int colum){
    for(int i = 0; i < 9; i++){
        if(i == colum) continue;
        if(board[row][i] == board[row][colum]) return false;
    }
    //check rows
    for(int i = 0; i <= 8; i++){
        if(i == row) continue;
        if(board[i][colum] == board[row][colum]) return false;
    }

    //check corners
    int start1 = (row / 3) * 3;
    int start2 = (colum / 3) * 3;

    for (int i = start1; i < start1 + 3; i++) {
        for (int j = start2; j < start2 + 3; j++) {
            if (i == row && j == colum) continue;
            if (board[i][j] == board[row][colum]) return false;
        }
    }
    
    return true;
}

bool solve_sudoku(vector<vector<int> >& board, int row, int colum){
    //base case
    if(row > 8) return true;
    if(colum > 8) return solve_sudoku(board, row + 1, 0);
    if(board[row][colum] != -1) return solve_sudoku(board, row, colum + 1);

    //main case
    for(int i = 1; i <= 9; i++){
        board[row][colum] = i;
        bool checked = check_square(board, row, colum);
        if(!checked || !solve_sudoku(board, row, colum + 1)){
            board[row][colum] = -1;
        }
        else return true;
    }
    return false;
}