#include <iostream>
#include <algorithm>

int main() {
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int n,m,score = 0;
    std::cin >> n >> m;
    char board[n][m];

    for (int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) std::cin >> board[i][j];

    char t;
    int q, row, col;
    std::cin >> q;
    while (q--) {
        std::cin >> row >> col >> t;

        int crow = row, ccol = col;
        if (t == 'L') ccol--;
        else ccol++;

        if (board[crow][ccol] == '-') {
            while (board[crow+1][ccol] == '-') crow++;

            board[crow][ccol] = board[row][col];
            board[row][col] = '-';

            bool ischange = true;
            while (ischange) {
                ischange = false;
                for (int i = 0 ; i < n-1 ; i++) {
                    for (int j = 0 ; j < m ; j++) {
                        if (board[i][j] != '-' && board[i][j] != '#' && board[i+1][j] == '-') {
                            std::swap(board[i][j], board[i+1][j]);
                            ischange = true;
                        } 
                    }
                }


                for (int i = 1 ; i < n-1 ; i++) {
                    for (int j = 1 ; j < m-1 ; j++) {
                        for (auto [dy,dx] : dirs) {
                            int y = i + dy, x = j + dx;
                            if (board[i][j] == board[y][x] && board[i][j] != '-' && board[i][j] != '#') {
                                score += 5;
                                board[i][j] = '-';
                                board[y][x] = '-';
                                ischange = true;
                            }
                        }
                    }
                }
                std::cout << "Process\n";
                for (int i = 0 ; i < n ; i++) {
                    for(int j = 0 ; j < m ; j++) std::cout << board[i][j];
                    std::cout << '\n';
                }
            }
        } else score-=5;
        for (int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) std::cout << board[i][j];
            std::cout << '\n';
        }
    }
    std::cout << score << '\n';
    for (int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) std::cout << board[i][j];
        std::cout << '\n';
    }
}