#include <iostream>
#include <vector>

using namespace std;

// 定义knight每个step可能的8种step策略
// int moveDirections[8][2] = {
//     {-2, -1}, // move 2 row up and move 1 column left
//     {-2, 1},  // move 2 row up and move 1 column rihgt
//     {2, -1}, // move 2 row down and move 1 column left
//     {2, 1},  // move 2 row down and move 1 column rihgt
//     {-1, -2}, // move 1 row up and move 1 colum left 
//     {-1, 2}, // move 1 row up and move 1 colum right
//     {1, -2}, // move 1 row down and move 1 colum left 
//     {1, 2} // move 1 row down and move 1 colum right
// }; 
int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2}; 
int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1}; 

void printTourPath(vector<vector<int>> &board) {
    for (auto r: board) {
        for (auto v: r) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// 查看board上的某个position 是否valid: 是否已经被访问过
bool isPositionValid(int x, int y, vector<vector<int>> &board) {
    if(x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] == -1) 
        return true;
    return false;
}


// start_x, start_y 初始位置的坐标
// board 棋盘
// tourStep 当前走过的步数
bool searchKnightTour(int start_x, int start_y, vector<vector<int>> &board, int tourStep) {
    int i, next_x, next_y;
    // tourStep 等于 64，完成了knight tour
    if (tourStep == 64) { 
        // printTourPath(board);
        return true;
    }
    // loop every possible move
    // for (auto move: moveDirections) {
    for (i = 0; i < 8; i++) {
        next_x = start_x + xMove[i];
        next_y = start_y + yMove[i];
        // check if the next position is valid or not
        if (isPositionValid(next_x, next_y, board)) {
            // 标注(next_x, next_y) 的值为当前的步数
            board[next_x][next_y] = tourStep;
            if (searchKnightTour(next_x, next_y, board, tourStep + 1)) {
                return true;
            };
            board[next_x][next_y] = -1;
        } 
    }
    return false;
}

int main () {
    cout << "start knight tour" << endl;
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}, 
        {-1, -1, -1, -1, -1, -1, -1, -1}
    };
    
    int start_x = 0;
    int start_y = 0;
    int tourStep = 1;
    board[start_x][start_y] = 0;
    if (searchKnightTour(start_x, start_y, board, tourStep)) {
        cout << "Solution found" << endl;
        printTourPath(board);
    } else {
        cout << "Solution does not exist" << endl;
    }
}