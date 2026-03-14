#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k,t,Cuse = 0 , ans = 0; std::cin >> n >> m >> k;

    std::vector<int> v(n);
    std::unordered_map<int,int> want,curr;

    for (int i = 0 ;  i < n ; i++) std::cin >> v[i];

    for (int i = 0 ; i < m ; i++) {
        std::cin >> t;
        want[t]++;
    }

    for (int i = 0 ; i < m ; i++) {
        if (want.find(v[i]) != want.end()) {
            curr[v[i]]++;
            if (curr[v[i]] <= want[v[i]]) Cuse++;
        }
    }

    if (Cuse >= k) ans++;

    for (int i = 0 ; i < n-m ; i++) {
        if (curr[v[i]] > 0) {
            if (curr[v[i]] <= want[v[i]]) Cuse--;
            curr[v[i]]--;
        }

        if (want.find(v[i+m]) != want.end()) {
            curr[v[i+m]]++;
            if (curr[v[i+m]] <= want[v[i+m]]) Cuse++;
        }

        
        if (Cuse >= k) ans++;
    }

    std::cout << ans;
}