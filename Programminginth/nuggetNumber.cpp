#include <iostream>

// precalculate ans
// static bool check[101] = {false};

// void recursive(int n) {
//     if (n > 100) return;

//     if (!check[n]) {
//         check[n] = true;
//     }

//     recursive(n+6);
//     recursive(n+9);
//     recursive(n+20);
// }

// int main() {
//     recursive(0);

//     for (int i = 1 ; i <= 100 ; i++) {
//         if (check[i]) std::cout << i << ',' << '\n';
//     }
// }

static int ans[] = {
    6,
    9,
    12,
    15,
    18,
    20,
    21,
    24,
    26,
    27,
    29,
    30,
    32,
    33,
    35,
    36,
    38,
    39,
    40,
    41,
    42,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    91,
    92,
    93,
    94,
    95,
    96,
    97,
    98,
    99,
    100
};

int main() {
    int n;
    std::scanf("%d", &n);
    if (n < 6) {std::printf("no"); return 0;}

    for (int i = 0 ; ans[i] <= n ; i++) std::printf("%d\n", ans[i]);
}