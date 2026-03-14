#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int dist , cy , cx;

    Node(int d , int y, int x) : dist(d) , cy(y) , cx(x) {};

    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n ,t , maxofmin = 0, x1=-1,y1,x2,y2;
    std::cin >> n;

    std::vector<std::vector<int>> v(n , std::vector<int>(n));
    std::vector<std::vector<bool>> visited(n , std::vector<bool>(n , false));

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            std::cin >> v[i][j];
            if (v[i][j]==0) {
                if (x1 == -1) x1=j , y1=i;
                else x2=j , y2 = i;
            }
        }
    }

    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};

    std::priority_queue<Node , std::vector<Node> , std::greater<Node>> pq;
    pq.push({0 , y1,x1});

    while (!pq.empty()) {
        auto [dist , cy , cx] = pq.top();
        pq.pop();

        if (cy == y2 && cx == x2) {
            std::cout << maxofmin;
            break;
        }

        maxofmin = std::max(dist , maxofmin);

        for (int i = 0 ; i < 4 ; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]) {
                pq.push({v[ny][nx] , ny , nx});
                visited[ny][nx] = true;
            }
        }
    }
}