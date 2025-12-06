#include <iostream>
#include <cmath>

static double sqrt2 = std::sqrt(2);

int main() {
    double x=0,y=0, val;
    std::string temp;

    while (std::cin >> temp && temp != "*") {
        val = 0;
        std::string dir = "";
        for (char c : temp) {
            if (c >= '0' && c <= '9') val = val*10 + (c-'0');
            else dir += c;
        }

        if      (dir == "N") y += val;
        else if (dir == "E") x += val;
        else if (dir == "S") y -= val;
        else if (dir == "W") x -= val;
        else if (dir == "NE") x+= val / sqrt2, y+= val / sqrt2;
        else if (dir == "SE") x+= val / sqrt2, y-= val / sqrt2;
        else if (dir == "SW") x-= val / sqrt2, y-= val / sqrt2;
        else if (dir == "NW") x-= val / sqrt2, y+= val / sqrt2;
        std::cout << x << ' ' << y << '\n';
    }

    std::printf("%.3f %.3f\n%.3f", x, y, std::sqrt(x*x + y*y));
}