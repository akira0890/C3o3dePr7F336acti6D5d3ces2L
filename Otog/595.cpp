#include <iostream>
#include <vector>
#include <algorithm>

#define psv std::pair<std::string , std::vector<int>>

struct Compare {
    bool operator()(const psv& a , const psv& b) {
        for (int i = 0 ; i < 26 ; i++) {
            if (a.second[i] != b.second[i]) return a.second[i] > b.second[i];
        }

        return a.first < b.first;
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<psv> v(n , std::make_pair<std::string , std::vector<int>>("" , std::vector<int>(26,0)));

    std::string s;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> s;
        v[i].first = s;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') v[i].second[c-'a']++;
        }
    }

    std::sort(v.begin() , v.end() , Compare());

    for (psv i : v) {
        std::cout << i.first << '\n';
    }
}