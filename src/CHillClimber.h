#pragma once

#include "CGrid.h"
#include <vector>
#include <string>
#include <iostream>
#include <sys/select.h>
#include <termios.h>
#include <set>

#define MAX_ITERS 100000
#define MAX_RESTARS 100

class CHillClimber {
public:
    void hillClimb(CGrid& input);
    void printFoundSol();
private:
    void fillMatrix();
    static int countFitness(CGrid& grid);
    bool isMovable(int x, int y);
    static bool isLegit(CGrid& grid);

    void swapTwoNodes( CGrid& grid );
    void permuteRow( CGrid& grid );

    CGrid createRandomNeighbour(CGrid& grid);

    uint32_t tries = 0;
    uint32_t restarts = 0;
    uint32_t minFitness = UINT32_MAX;

    CGrid foundSol;
    CGrid starter;
    CGrid filledGrid;

    bool foundSolution = false;
    std::set<std::vector<std::vector<int>>> seen;
};
