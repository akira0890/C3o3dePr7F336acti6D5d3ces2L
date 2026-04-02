#include <iostream>
#include <unordered_set>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::unordered_set<std::string> m;
    int n; std::cin >> n;
    int ans = n;
    
    std::string s;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> s;

        bool found = false;

        for (int idx = 0 ; idx < s.length()-4 ; idx++) {
            if (s[idx] == '_' && s[idx+1] == 'B' && s[idx+2] == 'u' && s[idx+3] == 't' && s[idx+4] == '_') {
                std::string temp = s.substr(0 , idx);
                if (m.find(temp) != m.end()) ans--;
                m.emplace(temp);
                found = true;
                break;
            }
        }

        if (!found) {
            if (m.find(s) != m.end()) ans--;
            m.emplace(s);
        }
    }

    std::cout << ans;
}