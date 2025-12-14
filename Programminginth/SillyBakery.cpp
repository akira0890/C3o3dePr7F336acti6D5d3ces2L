#include <iostream>
#include <cmath>

int main() {
    float val[5] = {1,0.75,0.5,0.25,0.125};
    float sum = 0;
    int n,in;
    std::cin >> n;

    while (n--) {
        for (int i = 0 ; i < 5 ; i++) {
            std::cin >> in;
            sum += in * val[i];
        }
    }
    std::cout << int((sum + 1) * 10 / 10);
}








// ai code / straight method (just want to know)
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     long long A=0,B=0,C=0,D=0,E=0;
//     for (int i=0;i<n;i++){
//         long long a,b,c,d,e;
//         cin >> a >> b >> c >> d >> e;
//         A+=a; B+=b; C+=c; D+=d; E+=e;
//     }

//     long long whole = 0;
//     long long half = 0, quarter = 0, eighth = 0;

//     // 1) เค้กเต็มปอนด์ (ต้องใช้ทั้งก้อน)
//     whole += A;

//     // 2) เค้ก 3/4: ต้องมาจาก "ตัดทั้งก้อน" เท่านั้น -> ได้เศษ 1/4 มาด้วย
//     whole += B;
//     quarter += B; // เศษจากการตัด 3/4 + 1/4

//     // 3) เค้ก 1/2: ตัดทั้งก้อนเป็น 2 ครึ่ง
//     if (C > 0) {
//         long long needWhole = (C + 1) / 2;     // 1 ก้อนให้ 2 ครึ่ง
//         whole += needWhole;
//         half += 2 * needWhole - C;             // ครึ่งที่เหลือ
//     }

//     // 4) เค้ก 1/4:
//     // ใช้เศษ 1/4 ที่มีอยู่ก่อน
//     if (D > 0) {
//         long long useQ = min(quarter, D);
//         quarter -= useQ;
//         D -= useQ;
//     }

//     // ถ้ายังต้องการ 1/4 เพิ่ม ใช้การตัดจากครึ่ง: 1/2 -> 2*(1/4)
//     if (D > 0 && half > 0) {
//         long long needHalf = (D + 1) / 2;          // 1 ครึ่งให้ 2 ไตรมาส
//         needHalf = min(needHalf, half);
//         half -= needHalf;
//         quarter += 2 * needHalf;                   // ได้ไตรมาสเพิ่ม
//         long long useQ = min(quarter, D);
//         quarter -= useQ;
//         D -= useQ;
//     }

//     // ถ้ายังต้องการ 1/4 เพิ่มอีก ต้องตัดจากทั้งก้อน: 1 ก้อน -> 4*(1/4)
//     if (D > 0) {
//         long long needWhole = (D + 3) / 4;
//         whole += needWhole;
//         quarter += 4 * needWhole;                  // ได้ไตรมาสเพิ่ม
//         quarter -= D;                              // ใช้ไปตามต้องการ
//         D = 0;
//     }

//     // 5) เค้ก 1/8:
//     // ก่อนอื่นใช้ eighth ที่มี (ปกติเริ่มต้นเป็น 0)
//     if (E > 0) {
//         long long useE = min(eighth, E);
//         eighth -= useE;
//         E -= useE;
//     }

//     // ใช้การตัดจากไตรมาส: 1/4 -> 2*(1/8)
//     if (E > 0 && quarter > 0) {
//         long long needQuarter = (E + 1) / 2;       // 1 ไตรมาสให้ 2 ชิ้น 1/8
//         needQuarter = min(needQuarter, quarter);
//         quarter -= needQuarter;
//         eighth += 2 * needQuarter;
//         long long useE = min(eighth, E);
//         eighth -= useE;
//         E -= useE;
//     }

//     // ถ้ายังต้องการ 1/8 เพิ่มอีก ต้องตัดจากทั้งก้อน: 1 ก้อน -> 8*(1/8)
//     if (E > 0) {
//         long long needWhole = (E + 7) / 8;
//         whole += needWhole;
//         // eighth += 8*needWhole; // ไม่จำเป็นต้องเก็บต่อแล้ว
//         // ใช้ไปจนหมด
//         E = 0;
//     }

//     cout << whole << "\n";
//     return 0;
// }
