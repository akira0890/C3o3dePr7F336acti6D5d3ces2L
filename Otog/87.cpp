#include <iostream>
#include <queue>

#define pii std::pair<int,int>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m; std::cin >> n >> m;

    std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;
    char cmd;
    int value , w;
    for (int i = 0 ; i < n+m ; i++) {
        std::cin >> cmd;
        if (cmd == 'T') {
            std::cin >> w >> value;
            pq.emplace(w , value);
        } else {
            if (!pq.empty()) {
                std::cout << pq.top().second << '\n';
                pq.pop();
            } else {
                std::cout << '0' << '\n';
            }
        }
    }
}