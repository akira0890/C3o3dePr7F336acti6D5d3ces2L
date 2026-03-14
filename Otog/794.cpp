/*
20 , 10 10
4 16
  3 12
*/

#include <iostream>
#include <unordered_map>

long long n , l , r , divs;
std::unordered_map<long long , long long> m;

long long recursive(long long curr) {
    if (curr < divs) {
        return 1;
    }

    auto it = m.find(curr);
    if (it != m.end()) return it->second;

    return m[curr] = recursive(curr * l / divs ) + recursive(curr * r /divs);

}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::cin >> n >> l >> r;
    divs = l+r;

    std::cout << recursive(n);
}