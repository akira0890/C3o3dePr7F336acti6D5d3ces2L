#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

struct Element {
    int val , original_index;
};

bool compareElements(const Element& a, const Element& b) {
    return a.val < b.val;
}

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n , ans = 0;
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<Element> sorted(n);

    for (int i = 0 ; i < n ; i++) {
        std::cin >> v[i];
        sorted[i] = {v[i],i};
    }

    std::sort(sorted.begin() , sorted.end() , compareElements);

    std::vector<int> where_is(n) , curr_pos(n);
    for (int i = 0 ; i < n ; i++) where_is[i] = i , curr_pos[i] = i;

    for (int i = 0 ; i < n ; i++) {
        int target_index = sorted[i].original_index;
        int curr_index_of_target = where_is[target_index];

        if (curr_index_of_target != i) {
            int element_at_i_original_index = curr_pos[i];

            where_is[element_at_i_original_index] = curr_index_of_target;
            where_is[target_index] = i;

            curr_pos[curr_index_of_target] = element_at_i_original_index;
            curr_pos[i] = target_index;
            ans++;
        }
    }

    std::cout << ans;
}

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int n , ans = 0;
//     std::cin >> n;
//     std::vector<int> v(n) , sorted(n);
//     std::map<int , int> index;

//     for (int i = 0 ; i < n ; i++) std::cin >> v[i] , index[v[i]] = i;

//     sorted = v;
//     std::sort(sorted.begin() , sorted.end());

//     for (int i = 0 ; i < n ; i++) {
//         if (v[i] != sorted[i]) {
//             int t1 = index[v[i]];
//             int t2 = index[sorted[i]];
//             index[v[i]] = t2;
//             index[sorted[i]] = t1;
//             std::swap(v[t1] , v[t2]);
//             ans++;
//         }
//     }

//     std::cout << ans;
// }