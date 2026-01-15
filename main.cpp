//Assignment: Project 7
//Main Driver

#include <iostream>
#include <fstream>
#include <string>
#include "citygraph.h"
#include "permutation.h"
#include "path.h"
using namespace std;

void visit(string& city);
void loadCityData(CityGraph& graph);
void loadCityGraphData(CityGraph& graph);
void exportCityDistances(const CityGraph& graph, const string cityNames[5]);
void displayAllPaths(const Path& pathManager, const string cityNames[5], ofstream& out);
void displayBestPath(const Path& pathManager, const string cityNames[5], ofstream& out);

int main() {
    string cityNames[5] = { "Reno", "San Francisco", "Salt Lake City", "Seattle", "Las Vegas" };

    CityGraph graph;
    loadCityGraphData(graph);
    exportCityDistances(graph, cityNames);

    graph.display(graph, cityNames);

    cout << "\nBFS from Reno:\n";
    graph.breadthFirstTraversal("Reno", visit);
    cout << endl;

    cout << "DFS from Reno:\n";
    graph.depthFirstTraversal("Reno", visit);
    cout << endl;

    Permutation permGen;
    int indices[] = { 1, 2, 3, 4 };
    permGen.generate(indices, 4);

    Path pathManager;
    pathManager.generatePaths(permGen);
    pathManager.calculateCosts(graph);

    ofstream outFile("tspresults.txt");
    if (!outFile) {
        cout << "Error: Could not open tspresults.txt for writing.\n";
        return 1;
    }

    displayBestPath(pathManager, cityNames, outFile);
    displayAllPaths(pathManager, cityNames, outFile);

    outFile.close();
    return 0;
}

void visit(string& city) {
    cout << city << " ";
}

void loadCityData(CityGraph& graph) {
    ifstream inFile("city_distances.txt");
    string from, to;
    int distance;

    if (!inFile) {
        cout << "Error: Could not open city_distances.txt\n";
        return;
    }

    while (inFile >> from >> to >> distance) {
        graph.add(from, to, distance);
    }

    inFile.close();
}

void loadCityGraphData(CityGraph& graph) {
    graph.add("Reno", "San Francisco", 218);
    graph.add("Reno", "Salt Lake City", 518);
    graph.add("Reno", "Las Vegas", 438);
    graph.add("San Francisco", "Seattle", 807);
    graph.add("Salt Lake City", "Seattle", 830);
    graph.add("Las Vegas", "Salt Lake City", 420);
}

void exportCityDistances(const CityGraph& graph, const string cityNames[5]) {
    ofstream out("city_distances.txt");
    if (!out) {
        cout << "Error: Could not open city_distances.txt.\n";
        return;
    }

    const int width = 16;

    out << string(width, ' ');
    for (int i = 0; i < 5; ++i) {
        out << cityNames[i];
        int spaces = width - cityNames[i].length();
        for (int s = 0; s < spaces; ++s)
            out << ' ';
    }
    out << '\n';

    for (int i = 0; i < 5; ++i) {
        out << cityNames[i];
        int rowSpaces = width - cityNames[i].length();
        for (int s = 0; s < rowSpaces; ++s)
            out << ' ';

        for (int j = 0; j < 5; ++j) {
            int distance = graph.getEdgeWeight(cityNames[i], cityNames[j]);

            out << distance;

            int digits = 1;
            int temp = distance;
            while (temp >= 10) {
                temp /= 10;
                digits++;
            }

            int pad = width - digits;
            for (int s = 0; s < pad; ++s)
                out << ' ';
        }
        out << '\n';
    }

    out.close();
}

void displayAllPaths(const Path& pathManager, const string cityNames[5], ofstream& out) {
    int totalPaths = pathManager.getPathCount();
    int path[6];

    cout << "All Possible Paths and Their Fuel Costs:\n\n";
    out << "All Possible Paths and Their Fuel Costs:\n\n";

    for (int i = 0; i < totalPaths; ++i) {
        pathManager.getPath(i, path);

        for (int j = 0; j < 6; ++j) {
            cout << cityNames[path[j]];
            out << cityNames[path[j]];
            if (j < 5) {
                cout << " -> ";
                out << " -> ";
            }
        }

        cout << " | Fuel: " << pathManager.getCost(i) << " gallons\n";
        out << " | Fuel: " << pathManager.getCost(i) << " gallons\n";
    }

    cout << endl;
    out << endl;
}

void displayBestPath(const Path& pathManager, const string cityNames[5], ofstream& out) {
    int bestPath[6];
    pathManager.getBestPath(bestPath);
    int bestCost = pathManager.getBestCost();

    cout << "Best Path (Minimum Fuel Cost):\n";
    out << "Best Path (Minimum Fuel Cost):\n";

    for (int i = 0; i < 6; ++i) {
        cout << cityNames[bestPath[i]];
        out << cityNames[bestPath[i]];
        if (i < 5) {
            cout << " -> ";
            out << " -> ";
        }
    }

    cout << " | Fuel: " << bestCost << " gallons\n\n";
    out << " | Fuel: " << bestCost << " gallons\n\n";
}
