// CityGraph Class

#ifndef CITY_GRAPH_H
#define CITY_GRAPH_H

#include <string>
#include <iostream>
#include "graph.h"
#include "arrayqueue.h"
#include "arraystack.h"

using namespace std;

const int MAX_CITIES = 5;

class CityGraph : public GraphInterface<string> {
private:
    string cities[MAX_CITIES];
    int adjacencyMatrix[MAX_CITIES][MAX_CITIES];
    int cityCount;
    int getIndex(const string& cityName) const;
    bool isValidCity(const string& cityName) const;

public:
    CityGraph();
    ~CityGraph();

    int getNumVertices() const override;
    int getNumEdges() const override;
    bool add(string start, string end, int edgeWeight) override;
    bool remove(string start, string end) override;
    int getEdgeWeight(string start, string end) const override;
    void depthFirstTraversal(string start, void visit(string&)) override;
    void breadthFirstTraversal(string start, void visit(string&)) override;

    void display(const CityGraph& graph, const string cityNames[5]) const;
};

#endif
