// #include <iostream>
// #include <vector>
// #include <iomanip>

// const long long MOD = 1e9;

// struct BigINT {
//     std::vector<long long> digits;

//     BigINT(int number = 0) {
//         if (number == 0) digits.emplace_back(0);
//         while (number) {
//             digits.emplace_back(number % MOD);
//             number /= MOD;
//         }
//     }

//     BigINT multipy(const BigINT& other) const {
//         BigINT res;
//         res.digits.resize(digits.size() + other.digits.size() , 0);

//         for (int i = 0 ; i < digits.size() ; i++) {
//             long long remain = 0;
//             for (int j = 0 ; j < other.digits.size() || remain; j++) {
//                 long long curr = res.digits[i+j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + remain;
//                 res.digits[i+j] = curr % MOD;
//                 remain = curr / MOD;
//             }
//         }

//         while (res.digits.size() > 1 && res.digits.back() == 0) res.digits.pop_back();

//         return res;
//     }
// };

// BigINT fastPower(long long b , long long expo) {
//     BigINT res(1);
//     BigINT base(b);
//     while (expo) {
//         if (expo & 1) res = res.multipy(base);
//         if (expo > 1) base = base.multipy(base);
//         expo >>= 1;
//     }
//     return res;
// }

// int main() {
//     std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

//     int a,b; std::cin >> a >> b;

//     if (a==0 && b==0) {std::cout << 1; return 0;}
//     if (a==0)         {std::cout << 0; return 0;}
//     if (b==0)         {std::cout << 1; return 0;}

//     BigINT res = fastPower(a,b);

//     std::cout << res.digits.back();
//     for (int i = res.digits.size()-2 ; i >= 0 ; i--) {
//         std::cout << std::setfill('0') << std::setw(9) << res.digits[i];
//     }
// }

// #include <iostream>
// #include <vector>
// #include <complex>
// #include <cmath>
// #include <algorithm>
// #include <iomanip>

// using namespace std;

// const double PI = acos(-1.0);

// // ฟังก์ชัน FFT: type = 1 สำหรับ FFT ปกติ, type = -1 สำหรับ Inverse FFT
// void fft(vector<complex<double>>& a, int type) {
//     int n = a.size();
//     for (int i = 1, j = 0; i < n; i++) {
//         int bit = n >> 1;
//         for (; j & bit; bit >>= 1) j ^= bit;
//         j ^= bit;
//         if (i < j) swap(a[i], a[j]);
//     }
//     for (int len = 2; len <= n; len <<= 1) {
//         double ang = 2 * PI / len * type;
//         complex<double> wlen(cos(ang), sin(ang));
//         for (int i = 0; i < n; i += len) {
//             complex<double> w(1);
//             for (int j = 0; j < len / 2; j++) {
//                 complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
//                 a[i + j] = u + v;
//                 a[i + j + len / 2] = u - v;
//                 w *= wlen;
//             }
//         }
//     }
//     if (type == -1) {
//         for (auto& x : a) x /= n;
//     }
// }

// struct BigINT {
//     vector<int> digits;
//     static const int BASE = 10; // FFT กับ BigInt แนะนำใช้ฐาน 10 เพื่อความแม่นยำของ double

//     BigINT(long long n = 0) {
//         if (n == 0) digits.push_back(0);
//         while (n > 0) {
//             digits.push_back(n % BASE);
//             n /= BASE;
//         }
//     }

//     BigINT multiply(const BigINT& other) const {
//         vector<complex<double>> fa(digits.begin(), digits.end()), fb(other.digits.begin(), other.digits.end());
//         int n = 1;
//         while (n < digits.size() + other.digits.size()) n <<= 1;
//         fa.resize(n); fb.resize(n);

//         fft(fa, 1);
//         fft(fb, 1);
//         for (int i = 0; i < n; i++) fa[i] *= fb[i];
//         fft(fa, -1);

//         BigINT res;
//         res.digits.resize(n);
//         long long carry = 0;
//         for (int i = 0; i < n; i++) {
//             long long cur = (long long)(fa[i].real() + 0.5) + carry;
//             res.digits[i] = cur % BASE;
//             carry = cur / BASE;
//         }
//         while (res.digits.size() > 1 && res.digits.back() == 0) res.digits.pop_back();
//         return res;
//     }
// };



// BigINT fastPower(long long a_val, long long b_val) {
//     BigINT res(1);
//     BigINT base(a_val);
//     while (b_val > 0) {
//         if (b_val & 1) res = res.multiply(base);
//         if (b_val > 1) base = base.multiply(base);
//         b_val >>= 1;
//     }
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     long long a, b;
//     if (!(cin >> a >> b)) return 0;

//     if (a == 0 && b == 0) { cout << 1 << endl; return 0; }
//     if (a == 0) { cout << 0 << endl; return 0; }
//     if (b == 0) { cout << 1 << endl; return 0; }

//     BigINT res = fastPower(a, b);
//     for (int i = (int)res.digits.size() - 1; i >= 0; i--) {
//         cout << res.digits[i];
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iomanip>

// using namespace std;

// const int MOD = 998244353;
// const int G = 3;
// const int BASE = 1000;

// int a_tmp[1 << 20], b_tmp[1 << 20];

// long long power(long long a, long long b) {
//     long long res = 1;
//     a %= MOD;
//     while (b) {
//         if (b & 1) res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }

// void ntt(int* a, int n, bool invert) {
//     for (int i = 1, j = 0; i < n; i++) {
//         int bit = n >> 1;
//         for (; j & bit; bit >>= 1) j ^= bit;
//         j ^= bit;
//         if (i < j) swap(a[i], a[j]);
//     }
//     for (int len = 2; len <= n; len <<= 1) {
//         long long wlen = power(G, (MOD - 1) / len);
//         if (invert) wlen = power(wlen, MOD - 2);
//         for (int i = 0; i < n; i += len) {
//             long long w = 1;
//             for (int j = 0; j < len / 2; j++) {
//                 int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % MOD);
//                 a[i + j] = (u + v) % MOD;
//                 a[i + j + len / 2] = (u - v + MOD) % MOD;
//                 w = w * wlen % MOD;
//             }
//         }
//     }
//     if (invert) {
//         long long n_inv = power(n, MOD - 2);
//         for (int i = 0; i < n; i++) a[i] = (int)(1LL * a[i] * n_inv % MOD);
//     }
// }

// struct BigINT {
//     vector<int> d;
//     BigINT(long long n = 0) {
//         if (n == 0) d.push_back(0);
//         while (n > 0) { d.push_back(n % BASE); n /= BASE; }
//     }

//     void multiply(const BigINT& other) {
//         if (d.empty() || (d.size()==1 && d[0]==0)) return;
//         int n = 1;
//         while (n < d.size() + other.d.size()) n <<= 1;

//         for (int i = 0; i < n; i++) {
//             a_tmp[i] = (i < d.size() ? d[i] : 0);
//             b_tmp[i] = (i < other.d.size() ? other.d[i] : 0);
//         }

//         ntt(a_tmp, n, false);
//         ntt(b_tmp, n, false);
//         for (int i = 0; i < n; i++) a_tmp[i] = (int)(1LL * a_tmp[i] * b_tmp[i] % MOD);
//         ntt(a_tmp, n, true);

//         d.clear();
//         long long carry = 0;
//         for (int i = 0; i < n; i++) {
//             long long cur = a_tmp[i] + carry;
//             d.push_back(cur % BASE);
//             carry = cur / BASE;
//         }
//         while (d.size() > 1 && d.back() == 0) d.pop_back();
//     }
// };

// BigINT fastPower(long long a, long long b) {
//     BigINT res(1), base(a);
//     while (b) {
//         if (b & 1) res.multiply(base);
//         if (b > 1) base.multiply(base);
//         b >>= 1;
//     }
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
    
//     long long a, b;
//     if (!(cin >> a >> b)) return 0;
//     if (a == 0 && b == 0) { cout << 1 << "\n"; return 0; }
//     if (a == 0) { cout << 0 << "\n"; return 0; }
//     if (b == 0) { cout << 1 << "\n"; return 0; }

//     BigINT res = fastPower(a, b);

//     cout << res.d.back();
//     for (int i = (int)res.d.size() - 2; i >= 0; i--) {
//         cout << setfill('0') << setw(3) << res.d[i];
//     }
//     cout << "\n";

//     return 0;
// }

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int G = 3;
const int MAXN = 1 << 20;

int a_tmp[MAXN], b_tmp[MAXN], rev[MAXN], roots[MAXN];

inline int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

inline void prepare(int n) {
    static int last_n = -1;
    if (n == last_n) return;
    last_n = n;
    
    for (int i = 0; i < n; i++) 
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);

    int w_base = power(G, (MOD - 1) / n);
    roots[n / 2] = 1;
    for (int i = n / 2 + 1; i < n; i++) roots[i] = 1LL * roots[i - 1] * w_base % MOD;
    for (int i = n / 2 - 1; i >= 1; i--) roots[i] = roots[i << 1];
}

inline void ntt(int* a, int n, bool invert) {
    for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += (len << 1)) {
            for (int j = 0; j < len; j++) {
                int u = a[i + j];
                int v = 1LL * a[i + j + len] * roots[len + j] % MOD;
                a[i + j] = (u + v >= MOD ? u + v - MOD : u + v);
                a[i + j + len] = (u - v < 0 ? u - v + MOD : u - v);
            }
        }
    }
    
    if (invert) {
        reverse(a + 1, a + n);
        int n_inv = power(n, MOD - 2);
        for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * n_inv % MOD;
    }
}

struct BigINT {
    vector<int> d;
    BigINT(long long n = 0) {
        if (n == 0) d.push_back(0);
        while (n > 0) { d.push_back(n % 10); n /= 10; }
    }

    void multiply(const BigINT& other) {
        int sz1 = d.size(), sz2 = other.d.size();
        if (sz2 == 1 && other.d[0] == 1) return;
        
        int n = 1;
        while (n < sz1 + sz2) n <<= 1;
        prepare(n);
        
        for (int i = 0; i < n; i++) a_tmp[i] = (i < sz1 ? d[i] : 0);
        for (int i = 0; i < n; i++) b_tmp[i] = (i < sz2 ? other.d[i] : 0);

        ntt(a_tmp, n, false);
        ntt(b_tmp, n, false);
        for (int i = 0; i < n; i++) a_tmp[i] = 1LL * a_tmp[i] * b_tmp[i] % MOD;
        ntt(a_tmp, n, true);

        d.resize(n);
        long long carry = 0;
        for (int i = 0; i < n; i++) {
            long long cur = a_tmp[i] + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }

    // คูณตัวเอง (ลด NTT ไป 1 ครั้ง)
    void square() {
        int sz = d.size();
        if (sz == 1 && d[0] == 1) return;
        int n = 1;
        while (n < sz + sz) n <<= 1;
        prepare(n);
        for (int i = 0; i < n; i++) a_tmp[i] = (i < sz ? d[i] : 0);
        ntt(a_tmp, n, false);
        for (int i = 0; i < n; i++) a_tmp[i] = 1LL * a_tmp[i] * a_tmp[i] % MOD;
        ntt(a_tmp, n, true);
        d.resize(n);
        long long carry = 0;
        for (int i = 0; i < n; i++) {
            long long cur = a_tmp[i] + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }
};

inline BigINT fastPower(long long a, long long b) {
    BigINT res(1), base(a);
    while (b) {
        if (b & 1) res.multiply(base);
        if (b > 1) base.square();
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long a, b;
    if (cin >> a >> b) {
        if (a == 0 && b == 0) cout << 1;
        else if (a == 0) cout << 0;
        else if (b == 0) cout << 1;
        else {
            BigINT res = fastPower(a, b);
            string s = "";
            for (int i = (int)res.d.size() - 1; i >= 0; i--) s += (char)(res.d[i] + '0');
            cout << s;
        }
    }
    return 0;
}