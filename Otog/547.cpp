#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s , pattern;
    while (std::cin >> s && std::cin >> pattern) {
        std::vector<int> lps(pattern.length()+1,0);

        int n = s.length() , m = pattern.length();
        int len = 0 , i = 1 , j = 0;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int ans = 0;
        i=0;
        while (i < n) {
            if (s[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans++;
                j = lps[j-1];
            }

            else if (i < n && pattern[j] != s[i]) {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }

        std::cout << ans << '\n';
    }
}