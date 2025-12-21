/*
The problem is to find minimum price to buy all land when buying land increase land around it by 0.1 time.

Sol;
create function to find minimum price.
Loop through every land to buy and increase land around it and keep minimum value of current sum or current land price + minimum price from next buy (value from call function)
*/

#include <iostream>
#include <algorithm>

int n,m;
double grid[5][5];
bool visited[5][5];

double recursive(int N) {
    if (N == 0) return 0;

    double minsum = 2e9;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (!visited[i][j]) {
                
                visited[i][j] = true;
                double increase = grid[i][j] * 0.1;
                grid[i+1][j+1]  += increase;
                grid[i+1][j]    += increase;
                grid[i+1][j-1]  += increase;
                grid[i][j+1]    += increase;
                grid[i][j-1]    += increase;
                grid[i-1][j+1]  += increase;
                grid[i-1][j]    += increase;
                grid[i-1][j-1]  += increase;

                minsum = std::min(minsum , grid[i][j] + recursive(N-1));

                grid[i+1][j+1]  -= increase;
                grid[i+1][j]    -= increase;
                grid[i+1][j-1]  -= increase;
                grid[i][j+1]    -= increase;
                grid[i][j-1]    -= increase;
                grid[i-1][j+1]  -= increase;
                grid[i-1][j]    -= increase;
                grid[i-1][j-1]  -= increase;
                visited[i][j] = false;
            }
        }
    }

    return minsum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::printf("%.2lf", recursive(n*m));
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// int dir[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
// int n,m;
// double minsum = 1e9;
// double sum = 0;

// std::vector<std::vector<float>> grids(n , std::vector<float>(m));

// void recursive(std::vector<std::vector<float>> ngrid, std::vector<std::vector<bool>> selected, double currsum, int N) {
//     if (currsum > minsum) return;
//     if (N == n*m) {
//         minsum = std::min(minsum , currsum);
//         return;
//     }

//     for (int i = 0 ; i < n ; i++) {
//         for (int j = 0 ; j < m ; j++) {
//             if (selected[i][j]) continue;

//             std::vector<std::vector<float>> temp = ngrid;
//             selected[i][j] = true;
//             int increase = temp[i][j] * 0.1;
//             for (int d = 0 ; d < 8 ; d++) {
//                 int ni = i + dir[d][0];
//                 int nj = j + dir[d][1];
//                 if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
//                     temp[ni][nj] += increase;
//                 }
//             }
            
//             recursive(temp , selected , currsum + temp[i][j] , N+1);
//             selected[i][j] = false;
//         }
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     std::cin >> n >> m;
    
//     std::vector<std::vector<float>> grid(n , std::vector<float>(m));
//     std::vector<std::vector<bool>> selected(n , std::vector<bool>(m,false));

//     for (int i = 0 ; i < n ; i++) {
//         for (int j = 0 ; j < m ; j++) {
//             std::cin >> grid[i][j];
//         }
//     }

//     grids = grid;

//     recursive(grid, selected , 0, 0);

//     std::printf("%.2lf", minsum);
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// #include <set>

// int dir[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
// int n,m,temp = 0;
// double minsum = 1e9;
// double sum = 0;

// std::set<int> val;
// std::vector<std::vector<float>> grids(n , std::vector<float>(m));
// std::unordered_map<int , std::vector<std::pair<int,int>>> ind;

// void recursive(std::set<int>::iterator currindex, std::vector<std::vector<float>> ngrid, double currsum) {
//     if (currindex == val.end()) {
//         minsum = std::min(minsum , currsum);
//         std::printf("%d %lf\n\n", *currindex , currsum);
//         return;
//     }
    
//     int curr = *currindex;
//     std::vector<std::pair<int,int>> pairs = ind[curr];
//     for (auto [i,j] : pairs) {
//         int increase = ngrid[i][j] * 0.1;
//         for (int d = 0 ; d < 8 ; d++) {
//             int ni = i + dir[d][0];
//             int nj = j + dir[d][1];
//             if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
//                 ngrid[ni][nj] += increase;
//             }
//         }

//         double vsum = 0;
//         for (auto [y,x] : pairs) vsum += ngrid[y][x] , std::printf("%lf %lf\n",grids[y][x] , ngrid[y][x]);
        
//         recursive(++currindex, ngrid , currsum + vsum);
//     }
    
// }

// int main() {
//     std::cin >> n >> m;
    
//     std::vector<std::vector<float>> grid(n , std::vector<float>(m));

//     for (int i = 0 ; i < n ; i++) {
//         for (int j = 0 ; j < m ; j++) {
//             std::cin >> grid[i][j];
//             val.emplace(grid[i][j]);
//             ind[grid[i][j]].emplace_back(std::make_pair(i,j));
//         }
//     }

//     grids = grid;

//     recursive(val.begin() , grid , 0);

//     std::printf("%.2lf", minsum);
// }