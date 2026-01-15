// CityGraph Class

#include "citygraph.h"

CityGraph::CityGraph() {
    cityCount = 0;

    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    cities[0] = "Reno";
    cities[1] = "San Francisco";
    cities[2] = "Salt Lake City";
    cities[3] = "Seattle";
    cities[4] = "Las Vegas";

    cityCount = MAX_CITIES;
}

CityGraph::~CityGraph() {

}

int CityGraph::getIndex(const string& cityName) const {
    for (int i = 0; i < cityCount; ++i) {
        if (cities[i] == cityName) {
            return i;
        }
    }
    return -1;
}

bool CityGraph::isValidCity(const string& cityName) const {
    return getIndex(cityName) != -1;
}

int CityGraph::getNumVertices() const {
    return cityCount;
}

int CityGraph::getNumEdges() const {
    int total = 0;
    for (int i = 0; i < cityCount; ++i) {
        for (int j = i + 1; j < cityCount; ++j) {
            if (adjacencyMatrix[i][j] > 0) {
                total++;
            }
        }
    }
    return total;
}

bool CityGraph::add(string start, string end, int edgeWeight) {
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);

    if (startIndex == -1 || endIndex == -1 || edgeWeight <= 0) {
        return false;
    }

    adjacencyMatrix[startIndex][endIndex] = edgeWeight;
    adjacencyMatrix[endIndex][startIndex] = edgeWeight;

    return true;
}

bool CityGraph::remove(string start, string end) {
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);

    if (startIndex == -1 || endIndex == -1) {
        return false;
    }

    adjacencyMatrix[startIndex][endIndex] = 0;
    adjacencyMatrix[endIndex][startIndex] = 0;

    return true;
}

int CityGraph::getEdgeWeight(string start, string end) const {
    int startIndex = getIndex(start);
    int endIndex = getIndex(end);

    if (startIndex == -1 || endIndex == -1) {
        return -1;
    }

    return adjacencyMatrix[startIndex][endIndex];
}

void CityGraph::breadthFirstTraversal(string start, void visit(string&)) {
    int startIndex = getIndex(start);
    if (startIndex == -1) return;

    bool visited[cityCount] = {false};
    ArrayQueue<int> queue;

    queue.enqueue(startIndex);
    visited[startIndex] = true;

    while (!queue.isEmpty()) {
        int current = queue.peekFront();
        queue.dequeue();

        string city = cities[current];
        visit(city);

        for (int i = 0; i < cityCount; ++i) {
            if (adjacencyMatrix[current][i] > 0 && !visited[i]) {
                queue.enqueue(i);
                visited[i] = true;
            }
        }
    }
}

void CityGraph::depthFirstTraversal(string start, void visit(string&)) {
    int startIndex = getIndex(start);
    if (startIndex == -1) return;

    bool visited[cityCount] = {false};
    ArrayStack<int> stack;

    stack.push(startIndex);

    while (!stack.isEmpty()) {
        int current = stack.peek();
        stack.pop();

        if (!visited[current]) {
            visited[current] = true;

            string city = cities[current];
            visit(city);

            for (int i = cityCount - 1; i >= 0; --i) {
                if (adjacencyMatrix[current][i] > 0 && !visited[i]) {
                    stack.push(i);
                }
            }
        }
    }
}

void CityGraph::display(const CityGraph& graph, const string cityNames[5]) const {
    const int width = 16;

    cout << string(width, ' ');
    for (int i = 0; i < 5; ++i) {
        cout << cityNames[i];
        int spaces = width - cityNames[i].length();
        for (int s = 0; s < spaces; ++s)
            cout << ' ';
    }
    cout << '\n';

    for (int i = 0; i < 5; ++i) {
        cout << cityNames[i];
        int rowSpaces = width - cityNames[i].length();
        for (int s = 0; s < rowSpaces; ++s)
            cout << ' ';

        for (int j = 0; j < 5; ++j) {
            int distance = graph.getEdgeWeight(cityNames[i], cityNames[j]);

            cout << distance;

            int digits = 1;
            int temp = distance;
            while (temp >= 10) {
                temp /= 10;
                digits++;
            }

            int pad = width - digits;
            for (int s = 0; s < pad; ++s)
                cout << ' ';
        }
        cout << '\n';
    }
}
