#include <iostream>
#include <queue>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    long long n,k,t,curr = 0,sum = 0; std::cin >> n >> k;

    std::priority_queue<long long, std::vector<long long> , std::greater<long long>> pq;
    for (int i = 0 ; i < n ; i++) std::cin >> t , pq.emplace(t);

    while (curr < k) {
        curr++;
        sum += pq.top();
        long long val = pq.top() * 1.05;
        pq.pop();
        pq.emplace(val);
    }

    std::cout << sum;
}