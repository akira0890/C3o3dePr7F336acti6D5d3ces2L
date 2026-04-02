#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s , ans = ""; std::cin >> s;

    std::vector<std::string> stk;

    for (int i = 0 ; i < s.size() ; i++) {
        if (isalpha(s[i])) {
            std::string temp; temp.push_back(s[i]);
            stk.emplace_back(temp);
        } else {
            std::string temp;

            temp += '(';

            temp += stk[stk.size() - 2];
            temp += s[i];
            temp += stk[stk.size() - 1];
            stk.pop_back();
            stk.pop_back();

            temp += ')';

            ans = temp;

            stk.emplace_back(temp);
        }
    }

    std::cout << ans;
}