#pragma once
# include <iostream>
# include <vector>
# include <list>
# include <map>
using namespace std;

class Graph
{
    int V, E;
    vector<vector<int>> Edge;
public:
    friend int diameter(Graph&);
    friend int connectivity(Graph&);
    friend Graph build_random_graph(int, float);
    friend int Is_Isolated(Graph &);
    Graph(int);
    //Graph(Graph&);
    ~Graph() {};
    const int get_V();
    const int get_E();
    void set_E(int);
    void add_edge(int v, int w);
    const void print_graph();
    bool BFS(int , int*, /*int* pred,*/ int *, int );
};

