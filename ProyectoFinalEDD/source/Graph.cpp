#include "../headers/Graph.h"

void Graph::addEdge(int u, int v) {

    adjList[u].push_back(v);

    adjList[v].push_back(u);
}

void Graph::display() {

    cout << "\n===== GRAFO =====\n";

    for(int i = 0; i < SIZE; i++) {

        cout << i << " -> ";

        for(int neighbor : adjList[i]) {

            cout << neighbor << " ";
        }

        cout << endl;
    }
}

void Graph::BFS(int start) {

    bool visited[SIZE] = {false};

    queue<int> q;

    visited[start] = true;

    q.push(start);

    cout << "\n===== BFS =====\n";

    while(!q.empty()) {

        int vertex = q.front();

        q.pop();

        cout << vertex << " ";

        for(int neighbor
            : adjList[vertex]) {

            if(!visited[neighbor]) {

                visited[neighbor] = true;

                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

void Graph::DFSUtil(int vertex,
                    bool visited[]) {

    visited[vertex] = true;

    cout << vertex << " ";

    for(int neighbor
        : adjList[vertex]) {

        if(!visited[neighbor]) {

            DFSUtil(neighbor,
                    visited);
        }
    }
}

void Graph::DFS(int start) {

    bool visited[SIZE] = {false};

    cout << "\n===== DFS =====\n";

    DFSUtil(start,
            visited);

    cout << endl;
}