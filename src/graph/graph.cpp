#include "graph.hpp"
#include<string>
#include<iostream>
/*
* Implementing the graph class
*  v0.1
*/
    // Checks if the graph is directed or not
    bool Graph::isDirected(int value) {
        bool directed = false;

        if(value == 1) {
            directed = true;
        }

        return directed;
    }

    // Checks if the graph is ponderated or not 
    bool Graph::isPonderated(int value) {
        bool ponderated = false;

        if(value == 1) {
            ponderated = true;
        }

        return ponderated;
    }

    // Constructor 
    Graph::Graph(number_vertices count_vertices,number_edges count_edges, bool directed, bool ponderated) {
        this->count_vertices = count_vertices;
        this->count_edges = count_edges;
        this->directed = directed;
        this->ponderated = ponderated;
    } 

    // Add a new Vertex to the graph and return if its successfully
    bool Graph::add_vertex(Vertex *vertx) {
        bool vertex_addition = true;

        for(auto i : this->all_vertices_values) {
            if(i == vertx->get_vertex_value()) {
                vertex_addition = false;
                std::cout << "An error has occured: The vertex already exist in the graph!";
                break;
            } 
        }  
        
        if(vertex_addition)
        {
            this->all_vertices_values.push_back(vertx->get_vertex_value());
        }
        
        return vertex_addition;
    }

    // Checks if the vertx is already in the matrix, if it is not expand the matrix
    void Graph::has_space(Vertex *vertx){

        if(search_vertex(vertx) == NULL) {
            vertx->set_vertex_tag(all_vertices_values.size() + 1);
            all_edges_values.expand_matrix(vertx->get_vertex_tag());
        }

    }

    // Add a new Edge to the graph and return if its successfully
    bool Graph::add_edge(Vertex *first, Vertex *last, int value) {
        bool edge_addition;

        has_space(first);
        has_space(last);

        edge_addition = all_edges_values.insert(value,first->get_vertex_tag(),last->get_vertex_tag());

        return edge_addition;
    }

    // Checks if the vertex exist
    bool Graph::search_vertex(Vertex *vertx) {
        bool resp = false;

        if(vertx->get_vertex_tag() != -1 && vertx->get_vertex_tag() < all_vertices_values.size()) 
            resp = true;
          
        return resp;
    }

    // Print all the vertices values
    void Graph::print_vertices() {

        std::cout << "Vertices_Values = [ ";

        for(auto i : this->all_vertices_values) {
            std::cout << i << "";
        }

        std::cout << "]";

    }

    // Print all the edges values
    void Graph::print_edges() {
        
        std::cout << "Edges_Values = [ ";

        //Implementation in progress...

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