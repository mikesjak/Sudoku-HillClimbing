#pragma once

#include "CGrid.h"
#include "CHillClimber.h"
#include "CKeyHandler.h"

class CSolver {
public:
    static void solve();
private:
    static std::string chooseFile();
    static bool isFile(std::string& fp);
    static void welcomeMessage();
};