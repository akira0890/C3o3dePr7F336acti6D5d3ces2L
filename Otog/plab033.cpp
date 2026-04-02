#include <iostream>
#include <unordered_map>
#include <climits>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::string s;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> s;
        std::unordered_map<char , int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int mins  = INT_MAX, maxs = 0;
        for (auto [c , f] : freq) {
            mins = std::min(mins , f);
            maxs = std::max(maxs , f);
        }
        std::cout << freq.size() << ' ' << maxs << ' ' << mins << '\n';

    }
}