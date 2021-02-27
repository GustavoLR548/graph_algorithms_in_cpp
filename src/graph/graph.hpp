#ifndef graph_hpp
#define graph_hpp

#include "vertex.hpp"
#include <iostream>

using number_vertices = int32_t;
using number_edges = int32_t;

class Graph{
    number_vertices count_vertices;
    number_edges count_edges;
    bool directed;
    bool ponderated;
    
    public:
        bool isDirected(int value);
        bool isPonderated(int value);
        Graph(number_vertices count_vertices, number_edges count_edges, bool directed, bool ponderated);
        bool add_edge(Vertex *initial, Vertex *last, int edge_value);
        bool add_vertex(Vertex *vertx);
        bool search_vertex(Vertex *vertx);
        short getVerticesNumber();  
        short getEdgesNumber();
        
        virtual std::string print();  
};

#endif