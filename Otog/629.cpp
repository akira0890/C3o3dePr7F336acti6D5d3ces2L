#include <iostream>
#include <vector>
#include <queue>

int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m;
    std::cin >> m >> n;

    std::vector<std::string> v(n);
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int square = 0 , diagonal = 0 , triangle = 0;

    std::vector<std::vector<bool>> visited(n , std::vector<bool>(m,false));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (!visited[i][j] && v[i][j] == '1') {
                std::queue<std::pair<int,int>> q;
                visited[i][j] = true;

                int minx = 10050,miny=10050,maxx=-1,maxy=-1;
                int cminx = 0   ,cminy = 0 ,cmaxx=0,cmaxy=0;
                int count = 1;

                q.emplace(i,j);
                while (!q.empty()) {
                    auto [y,x] = q.front();
                    q.pop();

                    for (int k = 0 ; k < 4 ; k++) {
                        int ny = y + move[k][0];
                        int nx = x + move[k][1];

                        if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && v[ny][nx] == '1') {
                            visited[ny][nx] = true;
                            count++;
                            if (ny <= miny) {
                                if (ny == miny) cminy++;
                                else miny = ny , cminy=1;
                            }
                            if (ny >= maxy) {
                                if (ny == maxy) cmaxy++;
                                else maxy = ny , cmaxy=1;
                            }
                            if (nx <= minx) {
                                if (nx == minx) cminx++;
                                else minx = nx , cminx=1;
                            }
                            if (nx >= maxx) {
                                if (nx == maxx) cmaxx++;
                                else maxx = nx ,  cmaxx=1;
                            }
                            q.emplace(ny,nx);
                        }
                    }
                }

                if (cminx > 1 && cminy > 1 && cmaxx > 1 && cmaxy > 1) {
                    if (cmaxx * cmaxy == count) square++;
                }
                else if (cminx == 1 && cminy == 1 && cmaxx == 1 && cmaxy == 1) {
                    int midx = (cminx + cmaxx) / 2;
                    int midy = (cminy + cmaxy) / 2;
                    int l    = cmaxx - cminx - 1;
                    if (cmaxx - cminx != cmaxy - cminy) continue;

                    bool isdiagonal = true;
                    for (int i = 0 ; i < cmaxy -  cminy ; i++) {
                        for (int j = 0 ; j < i*2+1 ; j++) {
                            if (v[cminy + i][midx - i + j] == '0') isdiagonal = false;
                        }
                    }
                    if (isdiagonal) diagonal++;
                }
                else {
                    bool istriangle = true;
                    if (cminx > 1) {
                        for (int i = cminy ; i <= cmaxy ; i++) {
                            for (int j = cminx ; j <= cminx + i-cminy ; j++) {
                                if (v[i][j] == '0') istriangle = false , std::cout << "triangle false at : " << i << ' ' << j << '\n';
                            }
                        }
                    } else if (cmaxx > 1) {
                        for (int i = cminy ; i <= cmaxy ; i++) {
                            for (int j = cmaxx ; j >= cmaxx - (i-cminy) ; j--) {
                                if (v[i][j] == '0') istriangle = false , std::cout << "triangle false at : " << i << ' ' << j << '\n';
                            }
                        }
                    } else if (cminy > 1) {
                        for (int j = cminx ; j <= cmaxx ; j++) {
                            for (int i = cminy ; i <= cmaxy ; i++) {
                                if (v[i][j] == '0') istriangle = false , std::cout << "triangle false at : " << i << ' ' << j << '\n';
                            }
                        }
                    } else if (cmaxy > 1) {
                        for (int j = cminx ; j <= cmaxx ; j++) {
                            for (int i = cmaxy ; i <= cmaxy - (j - cminx) ; i--) {
                                if (v[i][j] == '0') istriangle = false , std::cout << "triangle false at : " << i << ' ' << j << '\n';
                            }
                        }
                    }
                    if (istriangle) triangle++;
                }
            }
        }
    }

    std::cout << square << ' ' << diagonal << ' ' << triangle;
}