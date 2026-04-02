#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

int cVal[26];
int freq[26];

int main() {
    std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

    int n,m,k;
    std::string s;
    std::cin >> n >> s >> m;

    char c;
    int val;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> c >> val;
        cVal[c - 'A'] = val;
    }

    int maxs = 50000000 , maxf = 0;
    std::cin >> k;
    for (int i = 0 ; i < k ; i++) {
        freq[s[i]- 'A']++;
        maxs = std::max(maxs , freq[s[i]-'A']);
        if (freq[s[i]-'A'] == maxs) maxf++;
        if (maxs < freq[s[i]-'A']) {
            maxs = freq[s[i]-'A'];
            maxf = 1;
        }
    }
    long long sum = 0 , ans = LLONG_MIN;
    for (int i = 0 ; i < k ; i++) {
        if (freq[s[i]-'A'] != maxs) {
            sum += cVal[s[i]-'A'] * freq[s[i]-'A'];
        } else {
            if (maxf != 1) {
                sum += cVal[s[i]-'A'] * freq[s[i]-'A'];
            }
        }
    }
    ans = sum;

    for (int i = 0 ; i < n-k ; i++) {
        freq[s[i]-'A']--;
        if (freq[s[i]-'A']+1 == maxs) {
            maxf--;
            if (maxf == 1) {
                for (int j = 0 ; j < 26 ; j++) {
                    if (freq[j] == maxs) sum -= freq[j] * cVal[j];
                }
            }
        }

        freq[s[i+k]-'A']++;
        if (freq[s[i+k]-'A'] > maxs) {
            if (maxf == 1) {
                for (int j = 0 ; j < 26 ; j++) {
                    
                }
            }
            maxs = freq[s[i+k]-'A'];
        }
    }
}