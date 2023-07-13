#include "solver.h"


std::string CSolver::chooseFile() {
    std::string fileName;
    std::vector<std::string> files;
    std::cout << "Choose file to import: " << std::endl;
    int counter = 0;
    for (const auto & entry : std::filesystem::directory_iterator("../data/")) {
        fileName = entry.path();
        files.push_back(fileName);
        std::cout << counter++ << ". " << fileName << std::endl;
    }
    int choice;
    std::cin >> choice;
    if ( !isFile(fileName) ) throw std::invalid_argument("Bad file");
    return files[choice];
}

bool CSolver::isFile(std::string &fp) {
    return !(std::filesystem::is_directory(fp));
}

void CSolver::solve() {
    std::string fileName = chooseFile();
    CGrid g;
    g.load(fileName);
    std::cout << "Loaded input file!" << std::endl;
    std::cout << g << std::endl;
    CHillClimber hc;
    hc.hillClimb(g);
    hc.printFoundSol();
}
