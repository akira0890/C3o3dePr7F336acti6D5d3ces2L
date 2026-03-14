#include <iostream>
#include <queue>
#include <algorithm>

struct Node{
    int k , y , x;

    Node (int K , int Y, int X) : k(K) , y(Y) , x(X) {}
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , m , x , y; std::cin >> m >> n >> x >> y;
    std::vector<std::string> v(n);
    std::vector<std::vector<bool>> visited(n , std::vector<bool>(m , false));

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];

    std::queue<Node> q;
    q.emplace(Node{0,y,x});
    int found = 1000;

    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};

    std::vector<char> ans;

    while (!q.empty()) {
        auto [curr , cy , cx] = q.front();
        q.pop();

        if (found < curr) break;

        if (isupper(v[cy][cx])) {
            ans.emplace_back(v[cy][cx]);
            if (found == 1000) found = curr;
        }

        for (int i = 0 ; i < 4 ; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && v[ny][nx] != '1') {
                q.emplace(Node{curr+1 , ny , nx});
                visited[ny][nx] = true;
            }
        }
    }

    std::sort(ans.begin() , ans.end());

    for (char x : ans) std::cout << x << '\n';
}