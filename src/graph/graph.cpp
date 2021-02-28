#include "graph.hpp"
#include<string>
#include<iostream>
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
        bool vertex_addition = true;

        for(auto i : this->all_vertices_values) {
            if(i == vertx->get_vertex_value()) {
                vertex_addition = false;
            } 
        }  
        
        if (vertex_addition)
        {
            this->all_vertices_values.push_back(vertx->get_vertex_value());
        }
        
        return vertex_addition;
    }

    bool Graph::add_edge(Vertex *initial, Vertex *end, int value) {
        // Implementação da matrix...
    }

    bool Graph::search_vertex(Vertex *vertx) {
        // Implementação da lista...
    }

    // Print all the vertices values
    void Graph::print_vertices(){

        std::cout << "Vertices_Values = [ ";

        for(auto i : this->all_vertices_values) {
            std::cout << i << "";
        }

        std::cout << "]";

    }

    //Return the number of vertices the graph has
    short Graph::getVerticesNumber() {
        return this->count_vertices;
    }

    //Return the number of edges the graph has
    short Graph::getEdgesNumber() {
        return this->count_edges;
    }