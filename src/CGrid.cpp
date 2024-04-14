#include "CGrid.h"

bool CGrid::checkSqrt(int num) {
    int s = int(round(sqrt(num)));
    square = s;
    if ( num != (s*s) )
        return false;
    return true;
}

void CGrid::load( std::string& fileName ) {
    std::ifstream inFs{ fileName, std::ios::in | std::ios::binary };
    std::string line;
    std::getline(inFs, line);
    int s = int(std::stol(line));

    // Padding
    int tmp = s;
    while ( tmp > 10 ) {
        tmp /= 10;
        padding ++;
    }
    padding += 3;

    if ( !checkSqrt(s) )
        throw std::invalid_argument("Not a good sqrt\n");

    if ( s > maxBufferSize )
        throw std::invalid_argument("Max buffer size exceeded!\n");
    size = s;
    
    for ( int i = 0; i < size; i++ ) {
        std::vector<int> tmpVec;
        nums[i+1] = 0;
        for ( int j = 0; j < size; j++ ) {
            tmpVec.push_back(0);
        }
        grid.push_back(tmpVec);
    }

    for ( int i = 0; i < size; i++ ) {
        std::string buffer;
        getline(inFs, buffer);

        std::istringstream ss(buffer);

        for ( int j = 0; j < size; j++ ) {
            int curr;
            ss >> curr;
            if ( curr > size ) {
                throw std::invalid_argument("Invalid number in input!\n");
            }
            grid[i][j] = curr;
            nums[curr]++;
        }
    }
}

std::ostream &operator <<(std::ostream &os, const CGrid &grid) {
    std::vector<std::vector<char>> currM;

    // First row
    os << "╔";
    for ( int j = 0; j < grid.size; j++ ) {
        for ( int p = 0; p < grid.padding; p++ ) os << "═";
        if ( ((j+1) % grid.square == 0) && (j != grid.size-1) )
            os << "╦";
        else if ( j != grid.size-1 )
            os << "╤";
    }
    os << "╗" << std::endl;

    //Normal row
    for ( int i = 0; i < grid.size; i++ ) {
        os << "║";
        for ( int j = 0; j < grid.size; j++ ) {
            os << " " << std::setw(grid.padding-2) << std::setfill(' ');
            if ( grid.grid[i][j] ) {
                std::cout << grid.grid[i][j];
            }
            else {
                std::cout << " ";
            }
            std::cout << " ";
            if ( (j+1) % grid.square == 0 )
                os << "║";
            else if (j != grid.size-1 ) {
                os << "│";
            }
        }
        os << std::endl;
        if ( (((i+1) % grid.square) == 0) && i != grid.size -1) {
            os << "╟";
            for ( int j = 0; j < grid.size; j++ ) {
                for ( int p = 0; p < grid.padding; p++ ) os << "═";
                if ( (j+1) % grid.square == 0 && j != grid.size-1 )
                    os << "╬";
                else if ( j != grid.size-1 )
                    os << "┼";
            }
            os << "╢" << std::endl;
        }
        else if ( i != grid.size-1 ) {
            os << "╟";
            for ( int j = 0; j < grid.size; j++ ) {
                for ( int p = 0; p < grid.padding; p++) os << "─";
                if ( (j+1) % grid.square == 0 &&  j != grid.size-1 )
                    os << "╬";
                else if ( j != grid.size-1 )
                    os << "┼";
            }
            os << "╢" << std::endl;
        }
    }

    // Last row
    os << "╚";
    for ( int j = 0; j < grid.size; j++ ) {
        for ( int p = 0; p < grid.padding; p++ ) os << "═";
        if ( ((j+1) % grid.square == 0) && (j != grid.size-1) )
            os << "╩";
        else if ( j != grid.size-1 )
            os << "╧";
    }
    os << "╝" << std::endl;

    return os;
}

