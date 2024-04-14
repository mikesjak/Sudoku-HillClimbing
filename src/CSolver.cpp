#include "CSolver.h"

std::string CSolver::chooseFile() {
    std::string fileName;
    std::vector<std::string> files;
    std::cout << "Choose file to import: " << std::endl;
    int counter = 0;
    for (const auto & entry : std::filesystem::directory_iterator("data/")) {
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

void CSolver::welcomeMessage() {
    std::cout << "███████╗██╗   ██╗██████╗  ██████╗ ██╗  ██╗██╗   ██╗                                              \n"
                 "██╔════╝██║   ██║██╔══██╗██╔═══██╗██║ ██╔╝██║   ██║                                              \n"
                 "███████╗██║   ██║██║  ██║██║   ██║█████╔╝ ██║   ██║                                              \n"
                 "╚════██║██║   ██║██║  ██║██║   ██║██╔═██╗ ██║   ██║                                              \n"
                 "███████║╚██████╔╝██████╔╝╚██████╔╝██║  ██╗╚██████╔╝                                              \n"
                 "╚══════╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝                                               \n"
                 "                                                                                                 \n"
                 "██╗  ██╗██╗██╗     ██╗      ██████╗██╗     ██╗███╗   ███╗██████╗ ███████╗██████╗ ███████╗██████╗ \n"
                 "██║  ██║██║██║     ██║     ██╔════╝██║     ██║████╗ ████║██╔══██╗██╔════╝██╔══██╗██╔════╝██╔══██╗\n"
                 "███████║██║██║     ██║     ██║     ██║     ██║██╔████╔██║██████╔╝█████╗  ██████╔╝█████╗  ██████╔╝\n"
                 "██╔══██║██║██║     ██║     ██║     ██║     ██║██║╚██╔╝██║██╔══██╗██╔══╝  ██╔══██╗██╔══╝  ██╔══██╗\n"
                 "██║  ██║██║███████╗███████╗╚██████╗███████╗██║██║ ╚═╝ ██║██████╔╝███████╗██║  ██║███████╗██║  ██║\n"
                 "╚═╝  ╚═╝╚═╝╚══════╝╚══════╝ ╚═════╝╚══════╝╚═╝╚═╝     ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n"
                 "                                                                                                 " << std::endl;
}

void CSolver::solve() {
    std::system("clear");
    welcomeMessage();

    std::string fileName = chooseFile();
    CGrid g;

    g.load(fileName);
    std::cout << "\n\nLoaded input file!" << std::endl;
    std::cout << g << std::endl;

    std::cout << "Press Space and Enter to exit!\n" << std::endl;
    while ( true ) {
        while ( !CKeyHandler::kbhit() ) {}
        if ( CKeyHandler::getch() == 32 ) break;
    }

    CHillClimber hc;
    hc.hillClimb(g);
    hc.printFoundSol();
}