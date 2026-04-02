#include <iostream>
#include <vector>
#include <map>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<std::pair<int,int>> x(n);
    std::map<int , int> countx , county;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> x[i].first >> x[i].second;
        countx[x[i].first]++;
        county[x[i].second]++;
    }

    long long ans = 0;
    for (int i = 0 ; i < n ; i++) {
        ans += (long long)(countx[x[i].first]-1) * (long long)(county[x[i].second]-1);
    }

    std::cout << ans;
}