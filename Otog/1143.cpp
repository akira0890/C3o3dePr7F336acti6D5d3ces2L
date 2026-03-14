#include <iostream>

int prefix[500001];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,s,f;
    std::cin >> n >> m;

    for (int i = 0 ; i < m ; i++) {
        std::cin >> s >> f;
        prefix[s]++;
        prefix[f+1]--;
    }

    bool ans = false;
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        sum += prefix[i];
        if (sum==0) ans = true,std::cout << i << ' ';
    }

    if (!ans) std::cout << "-1";
}