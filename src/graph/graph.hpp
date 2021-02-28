#ifndef graph_hpp
#define graph_hpp

#include <list>

#include "vertex.hpp"

using number_vertices = int32_t;
using number_edges = int32_t;

class Graph{
    number_vertices count_vertices;
    number_edges count_edges;
    bool directed;
    bool ponderated;
    std::list<vertex_value> all_vertices_values;
    //std::matrix<edges_value> all_edges_values;

    public:
        bool isDirected(int value);
        bool isPonderated(int value);
        Graph(number_vertices count_vertices, number_edges count_edges, bool directed, bool ponderated);
        bool add_edge(Vertex *initial, Vertex *last, int edge_value);
        bool add_vertex(Vertex *vertx);
        bool search_vertex(Vertex *vertx);
        void print_vertices();
        short getVerticesNumber();  
        short getEdgesNumber();
        
        virtual std::string print();  
};

#endif