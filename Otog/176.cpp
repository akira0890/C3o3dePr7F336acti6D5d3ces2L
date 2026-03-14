#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int A,B;
    std::string s , res = "";
    std::cin >> A >> B >> s;

    std::vector<int> digit;
    for (char c : s) digit.emplace_back(c-'0');

    while (!digit.empty()) {
        long long remainer = 0;
        std::vector<int> next;

        for (int d : digit) {
            long long current = d+remainer*A;
            int quotient = current/B;
            remainer=current%B;

            if (!next.empty() || quotient > 0) {
                next.emplace_back(quotient);
            }
        }

        res += remainer + '0';
        digit = next;
    }

    if (res.empty()) std::cout << 0;
    else {
        std::reverse(res.begin() , res.end());
        std::cout << res;
    }
}