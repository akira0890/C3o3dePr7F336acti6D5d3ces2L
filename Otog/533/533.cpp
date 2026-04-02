#include <iostream>
#include "binary_search.h"

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    unsigned long long r = get_n()-1;
    unsigned long long l = 0;

    while (l <= r) {
        unsigned long long mid = l + (r-l)/2;

        if (is_equal(mid)) {
            answer(mid);
            return 0;
        } else if (is_less(mid)) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
}