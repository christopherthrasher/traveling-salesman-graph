## Traveling Salesman Problem – Graph Implementation

A C++ implementation of the Traveling Salesman Problem (TSP) solved using a weighted graph and a brute-force path evaluation approach. The program models cities as graph vertices, distances as weighted edges, and computes fuel cost based on a fixed miles-per-gallon metric.

## Overview
The program models a set of five cities:
- Reno
- San Francisco
- Salt Lake City
- Seattle
- Las Vegas

Distances between cities are represented as weighted edges in a graph. The program evaluates all possible paths that start in Reno, visit each city exactly once, and return to Reno. Each path’s cost is calculated based on a fuel efficiency of 40 miles per gallon.

## Features
- Custom graph data structure implementation
- Weighted edges representing distances between cities
- Brute-force solution to the Traveling Salesman Problem
- Path cost calculation based on fuel consumption
- Output of all possible routes and identification of the optimal path
- File-based input for distance data
- File-based output for route analysis
- Makefile-based build system

## Technologies & Concepts
- C++
- Graph data structures
- Brute-force algorithms
- Permutations and path evaluation
- File I/O

## How to Build and Run

### Prerequisites
- A C++ compiler that supports C++11 or newer (e.g., `g++`)
- `make` installed

### Build the Program
From the project root directory, run:
make

### Run the Program
./project7
- Object-Oriented Programming
- Makefile compilation
