#include "graph.hpp"
#include<string>
/*
* Implementing the graph class
*  v0.1
*/
    //Return the number of vertices the graph has
    short Graph::getVerticesNumber() {
        return this->vertices;
    }

    //Return the number of edges the graph has
    short Graph::getEdgesNumber() {
        return this->edges;
    }

    bool Graph::add_vertex(Vertex *vertx) {
        if(search_vertex(vertx) == true) {
            std::cout << "Error: Vertex already added!" << std::endl;  
        }
        else {

        }

        return true;

    }

    /* OBSERVAÇÕES
    - Pesquisar mais sobre os mapss
    - 
    */