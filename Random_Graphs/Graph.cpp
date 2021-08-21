
# pragma once
#include "Graph.h"

Graph::Graph(int V)
{
    Edge.resize(V);
    this->V = V;
    this->E = 0;
}
const int Graph::get_V() {
    return this->V;
}
const int Graph::get_E() {
    return this->E;
}
void Graph::set_E(int E)
{
    this->E = E;
}
void Graph::add_edge(int v, int w) {
    if (v < this->V && w < this->V) {
        Edge[v].push_back(w);
        //Edge[w].push_front(v);
        //this->E++;
    }
    else {
        if (v >= this->V)
            cout << "There is no Vertex " << v << " in this Graph" << endl;
        else
            cout << "There is no Vertex " << w << " in this Graph" << endl;
    }
}
const void Graph::print_graph()
{
    for (int i = 0; i < this->V; i++) {
        cout << "Vetex " << i << " ---> ";
        for (auto j : this->Edge[i]) {
            cout << j << " , ";
        }
        cout << endl;
    }
}

bool Graph::BFS(int num_of_V, int *diam, /* int* pred ,*/ int *dist, int src) {

    list<int> queue;
    bool* visited = new bool[num_of_V];

    // initiallization
    for (int i = 0; i < num_of_V; i++) {
        visited[i] = false;
        dist[i] = num_of_V + 1;
    //    //pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (auto i : Edge[u])
        {
            if (visited[i] == false) {
                visited[i] = true;
                dist[i] = dist[u] + 1;
                //pred[i] = u;
                queue.push_back(i);
            }
        }
    }
    for (int i = 0; i < num_of_V; i++) {
        if (dist[i] > * diam && dist[i] != num_of_V + 1) {
            *diam = dist[i];
        }
        else {
            if (dist[i] == num_of_V + 1) {
                delete[]visited;
                return false;
            }
        }
    }
    delete[]visited;
    return true;
}