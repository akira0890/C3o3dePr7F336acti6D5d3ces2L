#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii std::pair<unsigned long long, int>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,k; std::cin >> n >> k;;
    unsigned long long ans = 0;

    std::vector<int> v(n);

    for (int i = 0 ; i < n ; i++) std::cin >> v[i];
    std::sort(v.begin() , v.end());

    if (k == 1) {
        std::cout << 0;
        return 0;
    }

    int currk = 1;
    std::priority_queue<pii , std::vector<pii> , std::greater<pii>> pq;
    pq.push({(unsigned long long)v[0],0});

    while (!pq.empty()) {
        auto [sum , i] = pq.top();
        pq.pop();

        currk++;
        if (currk == k) {
            std::cout << sum;
            break;
        }

        if (i+1 < n) {
            pq.push({sum + v[i+1] , i+1});
            pq.push({sum - v[i] + v[i+1] , i+1});
        }
    }
}

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int n,value; std::cin >> n >> value; value--;
//     unsigned long long ans = 0;

//     unsigned long long maxs = std::min((unsigned long long)1 << n , (unsigned long long)20000000);
//     std::vector<int> v(n);
//     std::vector<unsigned long long> res(maxs);

//     for (int i = 0 ; i < n ; i++) std::cin >> v[i];
//     std::sort(v.begin() , v.end());

//     for (unsigned long long i = 0 ; i < 1ULL << n && i < 20000000 ; i++) {
//         unsigned long long sum = 0;
//         for (int j = 0 ; j < n ; j++) {
//             if (i & (1 << j)) sum += v[j];
//         }
//         res[i] = sum;
//     }

//     std::sort(res.begin() , res.end());

//     std::cout << res[value];
// }