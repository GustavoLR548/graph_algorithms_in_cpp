#ifndef graph_hpp
#define graph_hpp

#include "vertex.hpp"
#include "edge.hpp"
#include <iostream>

class Graph{

    protected:   
        short vertices;
        short edges;

    public:
        bool isDirected();
        bool isPonderated();
        Graph(bool directed, bool ponderated);
        bool add_edge(Vertex *initial, Vertex *last, int edge_value);
        bool add_vertex(Vertex *vertx);
        bool search_vertex(Vertex *vertx);
        short getVerticesNumber();  
        short getEdgesNumber();
        
        virtual std::string print();  
};

#endif