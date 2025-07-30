#include <iostream>
#include <assert.h>
#include <string>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

std::string formatColorPair(int pairNum, const char* major, const char* minor) {
    char buf[50];
    snprintf(buf, sizeof(buf), "%d | %s | %s", pairNum, major, minor);
    return std::string(buf);
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    assert(formatColorPair(0, "White", "Blue") == "0 | White | Blue");
    assert(formatColorPair(3, "White", "Brown") == "3 | White | Brown");
    assert(formatColorPair(4, "White", "Slate") == "4 | White | Slate");
    assert(formatColorPair(21, "Violet", "Orange") == "21 | Violet | Orange");
    assert(formatColorPair(24, "Violet", "Slate")  == "24 | Violet | Slate");
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}
