#pragma once

#define maxBufferSize 1000

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

class CGrid {
public:
    bool load( std::string& fileName );
    friend std::ostream& operator << (std::ostream& os, const CGrid& grid);
private:
    bool checkSqrt(int size);
    std::vector<std::vector<int>> grid;
    uint16_t size = 0;
    uint16_t square = 0;
    uint16_t padding = 0;
};
