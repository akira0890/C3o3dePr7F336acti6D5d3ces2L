#include<iostream>

int main() {
    char grid[11][62];
    int n;
    std::cin >> n;

    for (int i = 0 ; i < 11 ; i++) {
        for (int j = 0 ; j < 62 ; j++) {
            grid[i][j] = '.';
        }
    }

    int maxy=0,maxx=0;
    while (n--) {
        int x,h;
        std::cin >> x >> h;

        if (h > maxy) maxy = h;
        if (x+h+h-1 > maxx) maxx = x+h+h-1;

        for (int i = 0 ; i < h ; i++) {
            if (grid[i][x+i] != 'X') {
                if (grid[i][x+i] == '\\') grid[i][x+i] = 'v';
                else grid[i][x+i] = '/';
            }

            if (grid[i][x+h+h-1-i] != 'X') {
                if (grid[i][x+h+h-i-1] == '/') grid[i][x+h+h-1-i] = 'v';
                else grid[i][x+h+h-1-i] = '\\';
            }
        }

        for (int i = 0 ; i < h-1 ; i++) {
            for (int j = x+i+1 ; j < x+h+h-i-1 ; j++) {
                grid[i][j] = 'X';
            }
        }
    }

    for (int i = maxy-1 ; i >= 0 ; i--) {
        for (int j = 1 ; j <= maxx ; j++) {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }
}