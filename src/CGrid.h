#pragma once

#define maxBufferSize 1000

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

class CGrid {
public:
    void load( std::string& fileName );
    friend std::ostream& operator << (std::ostream& os, const CGrid& grid);

    uint16_t size = 0;
    uint16_t square = 0;
    std::vector<std::vector<int>> grid;
    std::map<int,int> nums;
private:
    bool checkSqrt(int size);
    uint16_t padding = 0;
};
