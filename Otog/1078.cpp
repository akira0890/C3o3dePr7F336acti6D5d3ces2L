#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define pii std::pair<long long,long long>

struct compare{
    bool operator()(const pii& a , const pii& b) const {
        if (a.first - a.second == b.first - b.second) {
            return a.first > b.first;
        }

        return (a.first - a.second > b.first - b.second);
    }
};

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n; std::cin >> n;
    std::vector<pii> v(n);
    
    for (int i = 0 ; i < n ; i++) {
        std::cin >> v[i].first >> v[i].second;
    }
    
    std::sort(v.begin() , v.end() , compare());
    
    long long l = 0 , r = 2e15 , prefix=0;
    long long ans = 0;

    while (l <= r) {
        bool check = true;
        long long mid = l + (r-l)/2;
        long long sum = mid;

        for (int i = 0 ; i < n ; i++) {
            if (sum < v[i].first) {
                check = false;
                break;
            }

            sum -= v[i].second;
        }

        if (check) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    std::cout << ans;

}




// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Chili {
//     long long a, b;
// };

// bool compareChili(const Chili& x, const Chili& y) {
//     return x.b > y.b;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;
//     vector<Chili> v(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i].a >> v[i].b;
//     }

//     sort(v.begin(), v.end(), compareChili);

//     long long current = 0;
//     long long total_needed = 0;

//     for (int i = 0; i < n; i++) {
//         if (current < v[i].a) {
//             total_needed += (v[i].b);
//             current = v[i].a;
//         }
//         current -= v[i].b;
//     }

//     cout << total_needed << endl;

//     return 0;
// }