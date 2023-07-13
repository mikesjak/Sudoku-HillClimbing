#pragma once
#include "grid.h"

bool CGrid::checkSqrt(int num) {
    int s = round(sqrt(num));
    square = s;
    if ( num != (s*s) )
        return false;
    return true;
}

bool CGrid::load( std::string& fileName ) {
    std::ifstream inFs{ fileName, std::ios::in | std::ios::binary };
    std::string line;
    std::getline(inFs, line);
    int s = std::stol(line);
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
        std::vector<int> tmp;
        for ( int j = 0; j < size; j++ ) {
            tmp.push_back(0);
        }
        grid.push_back(tmp);
    }

    for ( int i = 0; i < size; i++ ) {
        std::string buffer;
        getline(inFs, buffer);

        std::istringstream ss(buffer);

        for ( int j = 0; j < size; j++ ) {
            ss >> grid[i][j];
        }
    }
    return true;
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
            os << " " << std::setw(grid.padding-2) << std::setfill(' ') << grid.grid[i][j] << " ";
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

