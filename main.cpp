#include "solver.h"

int main() {

    CSolver solver;

    try {
        solver.solve();
    }
    catch ( std::exception& ex ) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
