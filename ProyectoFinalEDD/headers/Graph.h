#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {

private:

    static const int SIZE = 10;

    vector<int> adjList[SIZE];

    void DFSUtil(int vertex,
                 bool visited[]);

public:

    void addEdge(int u, int v);

    void display();

    void BFS(int start);

    void DFS(int start);
};