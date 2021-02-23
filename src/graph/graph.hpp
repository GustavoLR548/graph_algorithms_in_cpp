#include "vertices.hpp"
#include<string>
/*
* Implementing the graph class
*  v0.1
*/
class Graph {
    protected:
        short vertices;
        short edges;

    public:

        //Return the number of vertices the graph has
        short getVerticesNumber() {
            return this->vertices;
        }

        //Return the number of edges the graph has
        short getEdgesNumber() {
            return this->edges;
        }

        //interface for implementing a function that prints the Graph to the terminal
        virtual std::string print() {
            std::string vertices = std::to_string(this->vertices);
            std::string edges    = std::to_string(this->edges);

            return "verticies: " + vertices + "\n" + "edges: " + edges + "\n";
        }
};
class ListGraph : public Graph{

};

class MatrixGraph : public Graph{

};