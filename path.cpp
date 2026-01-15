// Path Class

#include "path.h"

const string Path::CITY_NAMES[5] = {
    "Reno",
    "San Francisco",
    "Salt Lake City",
    "Seattle",
    "Las Vegas"
};

Path::Path() {
    pathCount = 0;
    bestIndex = -1;

    for (int i = 0; i < 120; ++i) {
        costs[i] = -1;
        for (int j = 0; j < 6; ++j) {
            paths[i][j] = -1;
        }
    }
}

void Path::generatePaths(const Permutation& p) {
    pathCount = p.getCount();

    for (int i = 0; i < pathCount; ++i) {
        int temp[4];
        p.getPermutation(i, temp);

        paths[i][0] = 0;
        for (int j = 0; j < 4; ++j) {
            paths[i][j + 1] = temp[j];
        }
        paths[i][5] = 0;
    }
}

void Path::calculateCosts(const CityGraph& graph) {
    bestIndex = -1;
    int minCost = 1000000;

    for (int i = 0; i < pathCount; ++i) {
        int totalDistance = 0;

        for (int j = 0; j < 5; ++j) {
            int from = paths[i][j];
            int to = paths[i][j + 1];
            totalDistance += graph.getEdgeWeight(CITY_NAMES[from], CITY_NAMES[to]);
        }

        costs[i] = totalDistance / 40;

        if (costs[i] < minCost) {
            minCost = costs[i];
            bestIndex = i;
        }
    }
}

int Path::getCost(int index) const {
    if (index < 0 || index >= pathCount) {
        return -1;
    }
    return costs[index];
}

void Path::getPath(int index, int output[6]) const {
    if (index < 0 || index >= pathCount) {
        for (int i = 0; i < 6; i++) {
            output[i] = -1;
        }
        return;
    }

    for (int i = 0; i < 6; i++) {
        output[i] = paths[index][i];
    }
}

int Path::getBestIndex() const {
    return bestIndex;
}

int Path::getBestCost() const {
    if (bestIndex >= 0 && bestIndex < pathCount) {
        return costs[bestIndex];
    }
    return -1;
}

void Path::getBestPath(int output[6]) const {
    if (bestIndex >= 0 && bestIndex < pathCount) {
        for (int i = 0; i < 6; ++i) {
            output[i] = paths[bestIndex][i];
        }
    } else {
        for (int i = 0; i < 6; ++i) {
            output[i] = -1;
        }
    }
}

int Path::getPathCount() const {
    return pathCount;
}
