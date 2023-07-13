#pragma once

#include "CGrid.h"
#include "CHillClimber.h"

class CSolver {
public:
    CSolver() = default;
    void solve();
private:
    static std::string chooseFile();
    static bool isFile(std::string& fp);
};