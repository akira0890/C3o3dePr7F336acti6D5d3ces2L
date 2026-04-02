#include <iostream>
#include <queue>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , use = 0;
    long long h , k;
    std::cin >> n >> h >> k;

    std::priority_queue<long long> pq;
    long long t;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> t;
        if (t > 0) pq.emplace(t);
        h -= t;
        if (h <= 0) {
            if (k > 0) {
                h += pq.top() * 2;
                pq.pop();
                k--;
                use++;
            } else {
                h += pq.top();
                pq.pop();
            }
        } else {
            use++;
        }
    }
    std::cout << use;
}