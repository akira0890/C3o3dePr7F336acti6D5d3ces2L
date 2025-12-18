/*
The problem want to find string of the press button (from table array)

Sol:
Initiaize table array and keep length of it (accord to the problem)
input first press button and press time and put that char in answer string
loop n-1 time and get move position and calculate move position to press button and put that character in the answer string.
if press button is 1 then resize answer string from delete button(1) time
*/

#include <iostream>
#include <algorithm>

int main() {
    static constexpr char table[10][4] = {
        {0}, {0},
        {'A','B','C'},
        {'D','E','F'},
        {'G','H','I'},
        {'J','K','L'},
        {'M','N','O'},
        {'P','Q','R','S'},
        {'T','U','V'},
        {'W','X','Y','Z'}
    };

    static constexpr char len[10] = {
        0,0,3,3,3,3,3,4,3,4
    };

    int n,pos,a,b,t;
    std::cin >> n;

    std::string ans;
    ans.reserve(n);

    std::cin >> pos >> t;
    t--;
    if (pos != 1) ans.push_back(table[pos][t % len[pos]]);

    while (--n) {
        std::cin >> a >> b >> t;
        pos += a + b * 3;
        t--;

        if (pos == 1) {
            int remove = std::min<int>(t+1, ans.size());
            ans.resize(ans.size() - remove);
        } else {
            ans.push_back(table[pos][t % len[pos]]);
        }
    }

    if (ans.empty()) std::cout << "null";
    else std::cout << ans;
}