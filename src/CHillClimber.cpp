#include "CHillClimber.h"

void CHillClimber::hillClimb(CGrid &input) {
    srand(time(nullptr));
    starter = input;

    fillMatrix();

    while ( restarts < MAX_RESTARS ){
        CGrid currSol = filledGrid;
        int currFitness = countFitness(currSol);
        if ( currFitness == 0 ) {
            foundSol = currSol;
            foundSolution = true;
            return;
        }
        seen.insert(currSol.grid);
        uint32_t currTries = 0;

        while ( currTries < MAX_ITERS ) {

            CGrid randNeighbour = createRandomNeighbour(currSol);

            if ( seen.count(randNeighbour.grid) == 0) {
                currTries++;
     
                currFitness = countFitness(randNeighbour);
                currSol = randNeighbour;
                seen.insert(randNeighbour.grid);

                if ( currFitness < minFitness && currFitness != 0 ) {
                    minFitness = currFitness;
                    foundSol = randNeighbour;
                    std::cout << "\n\n Found new minimum: "<< minFitness << std::endl;
                    std::cout << foundSol << std::endl;
                }

                if ( currFitness == 0 && isLegit(randNeighbour) ) {
                    foundSol = randNeighbour;
                    foundSolution = true;
                    tries += currTries;
                    return;
                }
            }
        }
        restarts++;
        if ( restarts != MAX_RESTARS ) {
            tries += currTries;
        }
    }
}

void CHillClimber::fillMatrix() {
    filledGrid = starter;

    for ( int i = 0; i < filledGrid.size; i++ ) {
        std::set<int> alreadyInNums;
        for ( int j = 0; j < filledGrid.size; j++ ) {
            if ( filledGrid.grid[i][j] != 0 )
                alreadyInNums.insert(filledGrid.grid[i][j]);
        }
        for ( int j = 0; j < filledGrid.size; j++ ) {
            if ( filledGrid.grid[i][j] == 0 ) {
                for ( int k = 1; k <= filledGrid.size; k++ ) {
                    if ( !alreadyInNums.count(k) ) {
                        filledGrid.grid[i][j] = k;
                        alreadyInNums.insert(k);
                        break;
                    }
                }
            }
        }
    }

    std::cout << "Filled grid:" << std::endl;
    std::cout << filledGrid << std::endl;
}

int CHillClimber::countFitness(CGrid &grid) {
    int sum = 0;
    for ( int i = 1; i <= grid.size; i++ ) {
        sum += i;
    }
    int fitness = 0;

    // Count rows
    for ( int i = 0; i < grid.size; i++ ) {
        int currSum = 0;
        for ( int j = 0; j < grid.size; j++ ) {
            currSum += grid.grid[i][j];
        }
        currSum -= sum;
        fitness += abs(currSum);
    }

    // Count columns
    for ( int j = 0; j < grid.size; j++ ) {
        int currSum = 0;
        for ( int i = 0; i < grid.size; i++ ) {
            currSum += grid.grid[i][j];
        }
        currSum -= sum;
        fitness += abs(currSum);
    }

    //count squares
    for ( int i = 0; i < grid.square; i++ ) {
        for ( int j = 0; j < grid.square; j++ ) {
            int currSum = 0;
            for ( int k = 0; k < grid.square; k++ ) {
                for ( int l = 0; l < grid.square; l++ ) {
                    currSum += grid.grid[(i*grid.square)+k][(j*grid.square)+l];
                }
            }
            currSum -= sum;
            fitness += abs(currSum);
        }
    }
    return fitness;
}

CGrid CHillClimber::createRandomNeighbour(CGrid &grid) {
    CGrid currSol = grid;
    permuteRow(currSol);

    int randomNum = rand() % 2;
    if ( randomNum ){
        swapTwoNodes(currSol);
    }

    return currSol;
}

void CHillClimber::printFoundSol() {
    if ( foundSolution ) {
        std::cout << "\n\nHillClimber found solution after " << tries << " tries." << std::endl;
        std::cout << foundSol << std::endl;
    }
    else {
        std::cout << "\n\nHillClimber wasn't able to find solution after " << tries << " tries." << std::endl;
    }
}

bool CHillClimber::isMovable(int x, int y) {
    if ( starter.grid[x][y] == 0 )
        return true;
    return false;
}

bool CHillClimber::isLegit(CGrid &grid) {
    for ( int i = 0; i < grid.size; i++ ) {
        std::set<int> included;
        for ( int j = 0; j < grid.size; j++ ) {
            included.insert(grid.grid[i][j]);
        }
        if ( included.size() != grid.size )
            return false;
    }

    for ( int j = 0; j < grid.size; j++ ) {
        std::set<int> included;
        for ( int i = 0; i < grid.size; i++ ) {
            included.insert(grid.grid[i][j]);
        }
        if ( included.size() != grid.size )
            return false;
    }

    for ( int i = 0; i < grid.square; i++ ) {
        for ( int j = 0; j < grid.square; j++ ) {
            std::set<int> included;
            for ( int k = 0; k < grid.square; k++ ) {
                for ( int l = 0; l < grid.square; l++ ) {
                    included.insert(grid.grid[(i*grid.square)+k][(j*grid.square)+l]);
                }
            }
            if ( included.size() != grid.size )
                return false;
        }
    }

    return true;
}

void CHillClimber::swapTwoNodes(CGrid &grid) {
    int first_X, second_X, row;
    first_X = second_X = row = 0;

    while(true) {
        first_X = rand() % grid.size;
        second_X = rand() % grid.size;
        row = rand() % grid.size;

        if ( first_X == second_X
          || !isMovable(row, first_X)
          || !isMovable(row, second_X))
            continue;

        std::swap(grid.grid[row][first_X], grid.grid[row][second_X]);
        break;
    }
}

void CHillClimber::permuteRow(CGrid &grid) {
    std::set<int> alreadyIncluded;
    int row = rand() % grid.size;
    auto prev = grid.grid[row];

    for ( int i = 0; i < grid.size; i++ ) {
        if ( starter.grid[row][i] != 0 )
            alreadyIncluded.insert(starter.grid[row][i]);
    }
    for ( int i = 0; i < grid.size; i++ ) {
        if ( !isMovable(row, i) ) continue;
        while ( true ) {
            int randomNum = (rand() % grid.size)+1;
            if ( !alreadyIncluded.count(randomNum) ) {
                alreadyIncluded.insert(randomNum);
                grid.grid[row][i] = randomNum;
                break;
            }
        }
    }

}

