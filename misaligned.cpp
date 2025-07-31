#include <iostream>
#include <assert.h>
#include <string>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

static std::string formatColorPair(int pairNum, const char* major, const char* minor) {
    char buf[50];
    snprintf(buf, sizeof(buf), "%d | %s | %s", pairNum, major, minor);
    return std::string(buf);
}

void testPrintColorMap() {
    struct PairCase {
        int pairNum;
        const char* major;
        const char* minor;
        const char* expected;
    };
    PairCase testCases[] = {
        {0, "White", "Blue", "0 | White | Blue"},
        {4, "White", "Slate", "4 | White | Slate"},
        {5, "Red", "Blue", "5 | Red | Blue"},
        {9, "Red", "Slate", "9 | Red | Slate"},
        {10, "Black", "Blue", "10 | Black | Blue"},
        {14, "Black", "Slate", "14 | Black | Slate"},
        {20, "Violet", "Blue", "20 | Violet | Blue"},
        {24, "Violet", "Slate", "24 | Violet | Slate"}
    };
    for(const auto& tc : testCases) {
        assert(formatColorPair(tc.pairNum, tc.major, tc.minor) == tc.expected);
    }

    int result = printColorMap();
    assert(result == 25);
}
