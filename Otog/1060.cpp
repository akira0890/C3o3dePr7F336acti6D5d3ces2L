#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    int last;
    long long sum;

    Node(int last , long long sum) : last(last) , sum(sum) {}

    bool operator<(const Node & other) {
        return sum < other.sum;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , k; std::cin >> n >> k;
    std::vector<std::vector<long long>> v(n , std::vector<long long>(n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = i ; j < n ; j++) {
            std::cin >> v[i][j];
        }
    }

    std::priority_queue<long long , std::vector<long long> , std::greater<long long>> top_k;
    top_k.emplace(0);
    std::priority_queue<Node> q;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i ; j < n ; j++) {
            q.emplace(j,0);
        }
    }

    while (!q.empty()) {
        Node curr = q.top();
        q.pop();

        if (top_k.size() < k) {
            top_k.emplace(curr.sum);
        } else {
            top_k.pop();
            top_k.emplace(curr.sum);
        }

        for (int i = curr.last+2 ; i < n ; i++) {
            for (int j = i ; j < n ; j++) {
                q.emplace(j,curr.sum + v[i][j]);
            }
        }

        if (q.size() > 50000) {
            while (q.size() > 50000) q.pop();
        }
    }

    for (int i = 0 ; i < k ; i++) {
        std::cout << ans[i] << ' ';
    }
}