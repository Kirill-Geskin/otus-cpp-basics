#include "CMin.h"
#include "CMax.h"
#include "CMean.h"
#include "CStdDev.h"
#include "CPct90.h"


int main() {
    // Statistical functions
    std::vector<IStatistics*> statistics;
    statistics.push_back(new CMin{});
    statistics.push_back(new CMax{});
    statistics.push_back(new CMean{});
    statistics.push_back(new CStdDev{});
    statistics.push_back(new CPct90{});

    double val = 0;
    while (std::cin >> val) {
        for (auto& statistic : statistics) {
            statistic->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (auto& statistic : statistics) {
        std::cout << statistic->name() << " = " << statistic->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (auto& statistic : statistics) {
        delete statistic;
    }

    return 0;
}