#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int y,x,dist;

    Node(int Y , int X , int Dist) : y(Y) , x(X) , dist(Dist) {}
};

int main() {
    // std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::vector<std::string> v(n);
    std::vector<std::vector<bool>> visited(n , std::vector<bool>(m,false));
    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    int starty, startx , endy , endx;
    std::cin >> starty >> startx >> endy >> endx;

    std::queue<Node> q;
    q.emplace(starty,startx , 0);

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int y = curr.y;
        int x = curr.x;
        if (y < 0 || y >= n || x < 0 || x >= m || visited[y][x]) continue;
        visited[y][x] = true;

        if (y == endy && x == endx) {
            std::cout << curr.dist;
            return 0;
        }

        switch (v[y][x]) {
            case '0':
                break;
            case '1':
                q.emplace(y-1,x,curr.dist+1);
                break;
            case '2':
                q.emplace(y,x+1,curr.dist+1);
                break;
            case '3':
                q.emplace(y+1,x,curr.dist+1);
                break;
            case '4':
                q.emplace(y,x-1,curr.dist+1);
                break;
            case '5':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                break;
            case '6':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y+1,x,curr.dist+1);
                break;
            case '7':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y,x-1,curr.dist+1);
                break;
            case '8':
                q.emplace(y+1,x,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                break;
            case '9':
                q.emplace(y,x-1,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                break;
            case 'A':
                q.emplace(y+1,x,curr.dist+1);
                q.emplace(y,x-1,curr.dist+1);
                break;
            case 'B':
                q.emplace(y+1,x,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                q.emplace(y,x-1,curr.dist+1);
                break;
            case 'C':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y+1,x,curr.dist+1);
                q.emplace(y,x-1,curr.dist+1);
                break;
            case 'D':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y,x-1,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                break;
            case 'E':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y+1,x,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                break;
            case 'F':
                q.emplace(y-1,x,curr.dist+1);
                q.emplace(y+1,x,curr.dist+1);
                q.emplace(y,x-1,curr.dist+1);
                q.emplace(y,x+1,curr.dist+1);
                break;
        }
    }
}