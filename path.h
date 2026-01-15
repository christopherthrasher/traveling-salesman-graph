// Path Class

#ifndef PATH_H
#define PATH_H

#include "citygraph.h"
#include "permutation.h"
#include <string>
using namespace std;

class Path {
private:
    int paths[120][6];
    int pathCount;
    int costs[120];
    int bestIndex;

public:
    static const string CITY_NAMES[5];
    Path();
    void generatePaths(const Permutation& perms);
    void calculateCosts(const CityGraph& graph);
    int getCost(int index) const;
    void getPath(int index, int output[6]) const;
    int getBestIndex() const;
    int getBestCost() const;
    void getBestPath(int output[6]) const;
    int getPathCount() const;
};

#endif
