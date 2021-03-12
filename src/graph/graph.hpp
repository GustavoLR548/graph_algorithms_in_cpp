#ifndef graph_hpp
#define graph_hpp

#include <vector>

#include "vertex.hpp"
#include "../utils/matrix_cpp/matrix.hpp"

using edge_value = int32_t;
using number_vertices = int32_t;
using number_edges = int32_t;

class Graph {
    number_vertices count_vertices;
    number_edges count_edges;
    int tag_count = 0;
    bool directed;
    bool ponderated;
    std::vector<vertex_value> all_vertices_values;
    Matrix<edge_value>* all_edges_values;

    public:
        
        //
        bool isDirected(int value);
        bool isPonderated(int value);

        //
        Graph(number_vertices count_vertices, number_edges count_edges, bool directed, bool ponderated);
        
        //
        void has_space(Vertex *vertx);
        bool add_edge(Vertex *first, Vertex *last, int edge_value);
        bool add_vertex(Vertex *vertx);
        bool search_vertex(Vertex *vertx);
        void print_vertices();
        void print_edges();
        
        // Get the number of vertices and edges in the graph
        short getVerticesNumber();  
        short getEdgesNumber();
          
};

#endif