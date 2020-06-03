#include <iostream>
#include <vector>

using namespace std;

int xMove[2] = {1, 0};
int yMove[2] = {0, 1}; 

bool isPositionValid(int x, int y, vector<vector<int>> &board) {
    if (x >= 0 && x <=3 && y >= 0 && y <=3 && board[x][y] != 0) {
        return true;
    }
    return false;
}

bool searchPath(int start_x, int start_y, int goal_x, int goal_y, vector<vector<int>> &board) {
    int next_x, next_y, i;
    // 如果到达goal则成功
    if (start_x == goal_x && start_y == goal_y) {
        return true;
    }
    for ( i = 0; i < 2; i ++ ) {
        next_x = start_x + xMove[i];
        next_y = start_y + yMove[i];
        if (isPositionValid(next_x, next_y, board)) {
            board[next_x][next_y] = 2;
            if (searchPath(next_x, next_y, goal_x, goal_y, board)) {
                return true;
            }
            board[next_x][next_y] = 0;
        }
    }
    return false;
}

void printPath(vector<vector<int>> &board) {
    for (auto r: board) {
        for (auto v: r) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "rat in maze" << endl;
    vector<vector<int>> board = {
        {1, 1, 1, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int start_x = 0;
    int start_y = 0;

    int goal_x = 3;
    int goal_y = 3;
    board[start_x][start_y] = 2;
    if (searchPath(start_x, start_y, goal_x, goal_y, board)) {
        printPath(board);
    } else {
        cout << "Path not found..." << endl ;
    }
    
}