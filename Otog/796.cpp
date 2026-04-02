#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::vector<std::string> ans;
    std::string s , curr;
    while (std::cin >> curr) {
        s += curr;
    }
    // std::cin >> s;
    
    int start = 0;
    for (int i = 6 ; i < s.length() ; i++) {

        // std::cout << s.substr(i-5 , 6) << ' ' << (s.substr(i-5,6) == "https:") << '\n';
        if (s[i] == ':' &&
            s[i-1] == 's' &&
            s[i-2] == 'p' &&
            s[i-3] == 't' &&
            s[i-4] == 't' &&
            s[i-5] == 'h') {
                // std::cout << s.substr(start , i-5) << ' ' << i << '\n';
                ans.emplace_back(s.substr(start,i-5-start));
                start = i-5;
            }
    }
    ans.emplace_back(s.substr(start , s.length()-start));

    // for (int i = 0 ; i < 41 ; i++) std::cout << i % 10; std::cout << '\n';
    for (std::string res : ans) std::cout << res << '\n';
}