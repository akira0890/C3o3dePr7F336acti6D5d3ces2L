#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    std::string s; std::cin >> s;

    int off = 0; 
    int on = 1;

    for (char c : s) {
        int next_off, next_on;
        if (isupper(c)) {
            next_off = std::min(off + 1, on + 1); 
            next_on = std::min(on, off + 1);  
        } else {
            next_off = std::min(off, on + 1); 
            next_on = std::min(on + 1, off + 1);
        }
        off = next_off;
        on = next_on;
    }

    std::cout << std::min(off , on);
}