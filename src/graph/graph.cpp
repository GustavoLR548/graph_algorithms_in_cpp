#include "graph.hpp"
#include<string>
/*
* Implementing the graph class
*  v0.1
*/
    bool Graph::isDirected(int value) {
        bool directed = false;

        if(value == 1) {
            directed = true;
        }

        return directed;
    }

    bool Graph::isPonderated(int value) {
        bool ponderated = false;

        if(value == 1) {
            ponderated = true;
        }

        return ponderated;
    }

    Graph::Graph(number_vertices count_vertices,number_edges count_edges, bool directed, bool ponderated) {
        this->count_vertices = count_vertices;
        this->count_edges = count_edges;
        this->directed = directed;
        this->ponderated = ponderated;
    } 

    bool Graph::add_vertex(Vertex *vertx) {
        if(search_vertex(vertx) == true) {
            std::cout << "Error: Vertex already added!" << std::endl;  
        } else {
            // Implementação com a lista...
        }

        return true;
    }

    bool Graph::add_edge(Vertex *initial, Vertex *end, int value) {
        // Implementação da matrix...
    }

    bool Graph::search_vertex(Vertex *vertx) {
        // Implementação da lista...
    }

    //Return the number of vertices the graph has
    short Graph::getVerticesNumber() {
        return this->count_vertices;
    }

    //Return the number of edges the graph has
    short Graph::getEdgesNumber() {
        return this->count_edges;
    }