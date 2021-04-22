#ifndef graph_hpp
#define graph_hpp

#define EMPTY -1

#define WHITE  0
#define YELLOW 1
#define RED    2

#include <vector>
#include "matrix_cpp/matrix.cpp"

using weight  = int;
using counter = uint16_t;

class Graph {

    private: 

        //Attributes
        counter vertices;
        counter edges;


        Matrix<weight>* graph;
        std::vector<std::vector<counter>> adj;

        //Functions:

        // Checks if the graph matrix have space, if does not, expand the matrix
        bool has_space();
        // Add a 'last' vertex to be adj to 'first'
        void add_adj(counter first,counter last);
        // Visit a specific vertex and verify the color of the adjs
        //This is a function only used in depth first search
        void visit_vertex(counter index, std::vector<counter>* colour);

    public:
        
        //Constructors

        //Start the Graph with three empty vertices
        Graph();
        //Start the Graph with 'vertices' number of vertices
        Graph(counter vertices);
        //Descontructor
        ~Graph();

        //Basic graph operations
        
        /** Add a new Edge, by giving the coordenates of the first and last vertex
         *  (Obs: There is also the option of adding a weight to the 
         *  Edge, but if not specified, the 'weight' will be 0 )
         */ 
        bool add_edge(counter first, counter last, weight weight = 0);
        // Add a new Vertex to the graph and return if it is successful 
        counter add_vertex();
        //Make a basic search with the id of the vertex
        bool search_vertex(counter id);
        // get number of vertices of the graph
        counter vertices_num();  
        // get number of edges of the graph
        counter edges_num();
        // Print all data about the graph
        virtual void print();  

        // Special algorithms

        /** Make a Depth First Search in the Graph
         * 
         *  Significance of the colours:
         * 
         *  WHITE: Not explored
         *  YELLOW: Visited, but there's still adjacents to visit 
         *  RED: Visited, along with the adjacents
         */
        bool depth_first_search(counter first);

        /** Make a Breadth First Search in the Graph
         * 
         *  Significance of the colours:
         * 
         *  WHITE: Not explored
         *  YELLOW: Visited, but there's still adjacents to visit 
         *  RED: Visited, along with the adjacents
         */
        bool breadth_first_search();
};

#endif