#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,t; std::cin >> n >> m;
    std::vector<int> price(n+1,0) , score(n+1,0);
    std::cin >> t;
    if (t >= 0) score[1] = t;
    else price[1] = -t;

    for (int i = 2 ; i <= n ; i++) {
        std::cin >> t;
        if (t >= 0) {
            price[i] = price[i-1];
            score[i] = score[i-1] + t;
        } else {
            price[i] = price[i-1] - t;
            score[i] = score[i-1];
        }
    } 

    for (int i = 0 ; i < n ; i++) std::cout << price[i] << ' '; std::cout << '\n';
    for (int i = 0 ; i < n ; i++) std::cout << score[i] << ' '; std::cout << '\n';

    int start , coin;
    for (int i = 0 ; i < m ; i++) {
        std::cin >> start >> coin;

        auto it = std::lower_bound(price.begin() + start , price.end() , price[start] + coin) - price.begin();

        if (it > n) it = n;
        std::cout << price[start] + coin << ' ' << it << ' ';
        std::cout << score[it] - score[start] << '\n';
    }
}