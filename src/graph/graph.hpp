#ifndef graph_hpp
#define graph_hpp

#define EMPTY -1

#define WHITE  0
#define YELLOW 1
#define RED    2

#include <vector>

using weight  = int;
using counter = uint16_t;

class Graph {

    private: 

        //Attributes
        counter vertices;
        counter edges;

        std::vector<std::vector<counter>> adj;
        std::vector<std::pair<weight,std::pair<counter,counter>>> edges_weights;
        //Functions:

        // Checks if the graph matrix have space, if does not, expand the matrix
        bool has_space();
        // Add a 'last' vertex to be adj to 'first'

        void add_adj(counter first,counter last);
        // Visit a specific vertex and verify the color of the adjs
        //This is a function only used in depth first search

        counter visit_vertex(counter index,counter parent, std::vector<counter>* colour);

        //Verify if a certain vertex exists
        bool has_vertex(counter id);

    public:
        
        //Constructors

        //Start the Graph with three empty vertices
        Graph();

        //Start the Graph with 'vertices' number of vertices
        Graph(counter vertices = 3);

        //Read a graph from a text file
        Graph(const char* path);

        // get number of vertices of the graph
        counter vertices_num();  

        // get number of edges of the graph
        counter edges_num();

        //Basic graph operations
        
        /** Add a new Edge, by giving the coordenates of the first and last vertex
         *  (Obs: There is also the option of adding a weight to the 
         *  Edge, but if not specified, the 'weight' will be 0 )
         */ 
        bool add_edge(counter first, counter last, weight weight = 0);

        // Add a new Vertex to the graph and return if it is successful 
        counter add_vertex();

        // Print all data about the graph
        virtual void print();  

        // Special algorithms

        /** Make a Depth First Search in the Graph and 
         * count all of the cycles inside of such Graph
         * 
         *  Significance of the colours:
         * 
         *  WHITE: Not explored
         *  YELLOW: Visited, but there's still adjacents to visit 
         *  RED: Visited, along with the adjacents
         */
        counter depth_first_search(counter first);

        /** Kruskal's Algorythm, with a method to count cycles
         * 
         * 
        */
        counter kruskal();
};      

#endif