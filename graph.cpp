#include <iostream>
#include <list>
#include <queue>
#include <set>

class Graph {
private:
    int V; // vertex num
    std::list<int>* adj;   // adjacency list
    void BFSUtil(int v, bool* visited);
    void DFSUtil(int v, bool* visited);
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void BFS();    // BFS
    void DFS();    // DFS
};

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int> [V];   // init adjacency list
}

Graph::~Graph() {
    delete [] adj;  // need [] attention!
    adj = nullptr;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFSUtil(int v, bool* visited) {
    std::queue<int> myqueue;
    visited[v] = true;
    myqueue.push(v);
    while (!myqueue.empty()) {
        v = myqueue.front();
        std::cout << v << " ";
        myqueue.pop();
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                myqueue.push(*it);
            }
        }
    }
}

void Graph::BFS() {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    for (int j = 0; j < V; ++j) {
        if (!visited[j]) {
            std::queue<int> myqueue;
            visited[j] = true;
            myqueue.push(j);
            while (!myqueue.empty()) {
                j = myqueue.front();
                std::cout << j << " ";
                myqueue.pop();
                for (auto it = adj[j].begin(); it != adj[j].end(); ++it) {
                    if (!visited[*it]) {
                        visited[*it] = true;
                        myqueue.push(*it);
                    }
                }
            }
        }
    }
}

void Graph::DFSUtil(int v, bool* visited) {
    visited[v] = true;
    std::cout << v << " ";
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            DFSUtil(*it, visited);
        }
    }
}

void Graph::DFS() {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    for (int j = 0; j < V; ++j) {
        if (!visited[j]) {
            DFSUtil(j, visited);
        }
    }
}
int main()
{
    int n;
    std::cin >> n;
    if (n <= 0)     return 0;
    int V(n);
    Graph g(V);     // create graph
    std::set<int> edgeInput[V];
    edgeInput[0].insert({1, 2});
    edgeInput[1].insert({3, 4});
//    edgeInput[3].insert({1, 2, 4});
//    edgeInput[2].insert({2, 1, 0});
    for (int i = 0; i < V; ++i) {
        for (auto it = edgeInput[i].begin(); it != edgeInput[i].end(); ++it) {
            g.addEdge(i, *it);     // insert edge
        }
    }
    std::cout << "DFS: " << std::endl;
    g.DFS();
    std::cout << "\nBFS: " << std::endl;
    g.BFS();
    return 0;
}
