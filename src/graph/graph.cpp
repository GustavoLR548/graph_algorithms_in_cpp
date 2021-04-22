#include "graph.hpp"
#include<iostream>
#include <array> 
/*
* Implementing the graph class
*  v0.1
*/

    // Start the graph with the 'min' size of Matrix
    Graph::Graph() {

        //Starting the matrix with EMPTY value
        weight default_value = EMPTY;
        this->graph          = new Matrix<weight>(3,default_value);

        this->vertices = 0;
        this->edges    = 0;
    }

    // Start the graph matrix with a set size
    Graph::Graph(counter v) {

        //Starting the matrix with EMPTY value
        weight default_value = EMPTY;
        this->graph          = new Matrix<weight>(v,default_value);
    
        this->edges    = 0;
        this->vertices = 0;

        for(int i =0 ; i < v; i++) 
            add_vertex();
    } 

    Graph::~Graph() {
        free(this->graph);
    }

    //Return the number of vertices the graph has
    counter Graph::vertices_num() {
        return this->vertices;
    }

    //Return the number of edges the graph has
    counter Graph::edges_num() {
        return this->edges;
    }

    counter Graph::add_vertex() {
        counter result = -1;
        counter pos    = this->vertices;

       // std::cout<< "[Graph]: verifying if there is enough space..." << std::endl;

        if(!has_space()) 
            this->graph->expand_matrix(1,EMPTY);

       //std::cout<< "[Graph]: Ok! Inserting on matriz..." << std::endl;

        this->graph->insert(pos,pos,pos);
        result = this->vertices;
        this->vertices++;

       // std::cout<< "[Graph]: Inserting in adj list..." << std::endl;

        std::vector<counter> it;
        this->adj.push_back(it);
        
       // std::cout<< "[Graph]: Adding vertex process is finished with success!" << std::endl;

        return result;
    }

    bool Graph::has_space(){
        bool result = false;

        if(this->vertices < this->graph->get_number_of_columns()) {
            result = true;
        }

        return result;
    }

    // Add a new Edge to the graph and return if the operation was a success
    bool Graph::add_edge(counter first, counter last, weight value) {
        bool result = false;

        if(has_vertex(first) && has_vertex(last)) {
            this->graph->insert(value,first,last);
            this->graph->insert(value,last,first);
            this->edges++;

            add_adj(first, last);
            add_adj(last, first);
            result = true;
        }

        return result;
    }

    bool Graph::has_vertex(counter id){
        bool result = false;

        if(id < this->graph->get_number_of_columns()) 
            result = true;

        return result;
    }

    void Graph::add_adj(counter first, counter last) {
        auto it = &this->adj.at(first);
        it->push_back(last);
    }

    void Graph::print() {

        std::cout << "Number of vertices: " << this->vertices << std::endl;
        std::cout << "Number of edges   : " << this->edges << std::endl; 

        std::cout << "\nLists of Adjs:\n"; 

        for(int i = 0; i < adj.size(); i++) {
            std::vector<counter> it = this->adj.at(i);
            std::vector<counter> :: iterator v;
            std::cout << "v[" << i << "] :"; 
            for(v = it.begin(); v != it.end() ;++v) {
                std::cout << ' ' << *v; 
            }
            std::cout << '\n'; 
        } 

        std::cout << "\nMatriz of Adjs:\n"; 

        this->graph->print(); 
    }

    bool Graph::depth_first_search(counter first) {
        std::vector<counter> colour;

        //Mark all vertices as : "NOT VISITED"
        for(int i = 0; i < this->vertices; i++)
            colour.push_back(WHITE);

        //Loop through all vertices in the graph
        for(counter i = 0; i < this->vertices; i++) 

            //if the curr vertex hasn't been visited
            if(colour.at(i) == WHITE) 

                //visiting current vertex
                //Obs: I'm sending a pointer to the 
                //memory address of the 'colour' std::vector
                //so that all recursive calls to 'visit_vertex'
                //can update when a vertex is visited
                visit_vertex(i,&colour);

        return true;
    }

    void Graph::visit_vertex (counter index, std::vector<counter>* colour) {
        //Mark current vertex as visited
        colour->at(index) = YELLOW;
        
        std::cout << "curr_index = " << index << std::endl;

        //Start adj std::vector
        std::vector<counter> curr_vertex_adj = this->adj.at(index); 

        //Loop through adj std::vector of the curr_vertex
        for(int i = 0 ; i < curr_vertex_adj.size(); i++) 

            //if adj vertex hasn't been visited
            if(colour->at(curr_vertex_adj.at(i)) == WHITE)

                //recursive call to 'visit_vertex'
                visit_vertex(curr_vertex_adj.at(i),colour);
        
        //Mark vertex as completed
        colour->at(index) = RED;
    }

    bool Graph::breadth_first_search() {
        std::vector<counter> colour;

        //Mark all vertices as : "NOT VISITED"
        for(int i = 0; i < this->vertices; i++)
            colour.push_back(WHITE);

        //Start the queue with the first vertice of the graph
        std::vector<counter> queue;
        queue.push_back(0);

        //While the queue is not empty
        while(queue.size() > 0) {

            //Remove the first element of the queue 
            //and store it in a variable
            counter curr_vert = *queue.begin();
            queue.erase(queue.begin());

            //If the element is not visited
            if(colour.at(curr_vert) == WHITE) {

                //Mark as visited
                colour.at(curr_vert) = YELLOW;

                std::cout << "curr_index = " << curr_vert << std::endl;

                //Start adj std::vector
                std::vector<counter> curr_vertex_adj = this->adj.at(curr_vert); 

                //Loop through adj std::vector of the curr_vertex
                for(int i = 0 ; i < curr_vertex_adj.size() ; i++) 

                    //if adj vertex hasn't been visited
                    if(colour.at(curr_vertex_adj.at(i)) == WHITE) {
                        //mark to be visited in the next iterations of the loop

                        queue.push_back(curr_vertex_adj.at(i));
                    }

                //mark the curr_vertex as completed
                colour.at(curr_vert) = RED;
            }
        }

        return true;
    }